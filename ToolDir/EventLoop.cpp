#include "EventLoop.h"

EventLoop::EventLoop(bool isDefault)
{
	if(isDefault)
		evLoop = ev_default_loop(0);
	else
		evLoop = ev_loop_new(EVFLAG_AUTO);
}

void EventLoop::loop()
{
	if(!evLoop)
		return;
	ev_loop(evLoop, 0);
}

void EventLoop::regTimer(TimerEvent* ev, ev_tstamp repeat, ev_tstamp after)
{
	if(evLoop && ev)
	{
		ev->evTimer.data = ev;
		ev_timer_init(&ev->evTimer, timerCallBack, after, repeat);
		ev_timer_start(evLoop, &ev->evTimer);
	}
}

void EventLoop::regSignal(SignalEvent* ev, int sig)
{
	if(evLoop && ev)
	{
		ev->evSignal.data = ev;
		ev_signal_init(&ev->evSignal, signalCallBack, sig);
		ev_signal_start(evLoop, &ev->evSignal);
	}
}

void EventLoop::stop()
{
	if(!evLoop)
		return;
	ev_break(evLoop, EVBREAK_ALL);
}

// test
int main()
{
	// 可以做一个线程池，后台处理数据
	// 主线程处理结果
	TimerEvent event;
	EventLoop::instance()->regTimer(&event, 2, 0);
	EventLoop::instance()->loop();
	return 0;
}
