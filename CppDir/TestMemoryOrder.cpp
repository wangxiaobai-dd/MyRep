#include <thread>
#include <iostream>

volatile int count = 0;

void increase() {
    for (int i = 0; i < 1000000; i++) {
        count++;
    }
}

void decrease() {
    for (int i = 0; i < 1000000; i++) {
        count--;
    }
}

int main() {
    std::thread t1(increase);
    std::thread t2(decrease);
    t1.join();
    t2.join();
    std::cout << count << std::endl;
}
