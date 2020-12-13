#pragma once
#include <ev.h>
#include <iostream>

struct TimerEvent
{
	public:
		friend class EventLoop;
		virtual void called()
		{
			std::cout << "timer called" << std::endl;
		}
	private:
		struct ev_timer evTimer;
};

struct SignalEvent
{
	public:
		friend class EventLoop;
		virtual void called()
		{
			std::cout << "signal called" << std::endl;
		}
		bool stopEvFlag = true;
	private:
		struct ev_signal evSignal;
};

static void timerCallBack(struct ev_loop* evLoop, ev_timer* evTimer, int revents)
{
	TimerEvent* ev = (TimerEvent*)evTimer->data;
	ev->called();
}
static void signalCallBack(struct ev_loop* evLoop, ev_signal* evSignal, int revents)
{
	SignalEvent* ev = (SignalEvent*)evSignal->data;
	ev->called();
	if(ev->stopEvFlag)
		ev_break(evLoop, EVBREAK_ALL);
}
class EventLoop
{
	public:
		EventLoop(bool isDefault = true);
		static EventLoop* instance()
		{
			static EventLoop loop;
			return &loop;
		}
		void regTimer(TimerEvent* ev, ev_tstamp repeat, ev_tstamp after = 0.0);
		void regSignal(SignalEvent* ev, int sig = SIGINT);
		void loop();
		void stop();
		struct ev_loop* evLoop;
};
