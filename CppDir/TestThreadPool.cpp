#include <vector>
#include <queue>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <stdexcept>
#include <chrono>
#include <iostream>

class ThreadPool {
	public:
		ThreadPool(size_t);
		template<class F, class... Args>
			auto enqueue(F&& f, Args&&... args)->std::future<typename std::result_of<F(Args...)>::type>;
		~ThreadPool();
	private:
		std::vector< std::thread > workers;
		std::queue< std::function<void()> > tasks;

		std::mutex queue_mutex;
		std::condition_variable condition;
		bool stop;
};

inline ThreadPool::ThreadPool(size_t threads): stop(false)
{
	for (size_t i = 0; i<threads; ++i)
		workers.emplace_back([this]
				{
				for (;;)
				{
				std::function<void()> task;

				{
				std::unique_lock<std::mutex> lock(this->queue_mutex);
				// pred 为true才解除阻塞
				this->condition.wait(lock,
						[this] { return this->stop || !this->tasks.empty(); });
				if (this->stop && this->tasks.empty())
				return;
				task = std::move(this->tasks.front());
				this->tasks.pop();
				}

				task();
				}
				}
				);
}

	template<class F, class... Args>
auto ThreadPool::enqueue(F&& f, Args&&... args)
	-> std::future<typename std::result_of<F(Args...)>::type>
{
	using return_type = typename std::result_of<F(Args...)>::type;

	auto task = std::make_shared< std::packaged_task<return_type()> >(
			std::bind(std::forward<F>(f), std::forward<Args>(args)...)
			);

	std::future<return_type> res = task->get_future();
	{
		std::unique_lock<std::mutex> lock(queue_mutex);

		if (stop)
			throw std::runtime_error("enqueue on stopped ThreadPool");

		tasks.emplace([task]() { (*task)(); });
	}
	condition.notify_one();
	return res;
}

int sum(int a, int b) {
	std::this_thread::sleep_for(std::chrono::seconds(10));
	return a + b;
}

inline ThreadPool::~ThreadPool()
{
	{
		// 比lockguard粒度小， 可控随时unlock  还可以deferlock
		std::unique_lock<std::mutex> lock(queue_mutex);
		stop = true;
	}
	condition.notify_all();
	for (std::thread &worker : workers)
		worker.join();
}

void read(std::future<std::string> *future) {
	// std::this_thread::sleep_for(seconds(2));
	// future会一直阻塞，直到有值到来
	std::cout << future->get() << std::endl;
}
int main()
{
	// future 测试
	/*
	std::promise<std::string> promise;
	std::future<std::string> future = promise.get_future();
	promise.set_value("hello future");
	std::thread thread(read, &future);
	thread.join();
	*/

	ThreadPool pool(3);
	auto future = pool.enqueue(sum, 1, 2);

	std::thread t1([&future]{ std::cout << future.get() << std::endl;});
	//t1.join();
	t1.detach();
	
	std::this_thread::sleep_for(std::chrono::seconds(20));
	// 可以把future 放入队列， EventLoop回调取结果
}
	     
