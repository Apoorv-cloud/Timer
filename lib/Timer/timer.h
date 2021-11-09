#ifndef TIMER_H
#define TIMER_H

#include <inttypes.h>

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#ifndef NULL
#define NULL 0
#endif

class Timer {
public:
	Timer();

	~Timer();
	void start();
	void stop();
	void pause();
	void reset();
	unsigned long getElapsedTime();
	void setInterval(unsigned long interval, int repeat_count=-1);
	void setTimeout(unsigned long timeout);
	void clearInterval();
	void setCallback(void (*function)(void)){
		this->function_callback = function;
	}
	void update();

	bool isPaused();
	bool isStopped();
	bool isRunning();

protected:
	virtual void call();

private:
	unsigned long initial_time;
	unsigned long current_time;

	bool is_running;
	bool is_paused;

	unsigned long interval;
	unsigned long last_interval_time;
	int repeat_count;
	int total_repeat_count;
	bool interval_is_setted;

	void (*function_callback)(void);
};

template <class Obj>

class TimerForMethods: public Timer {
public:
	TimerForMethods(Obj *object, void (Obj::*callback)(void)) {
		this->object = object;
		this->method = callback;
	}

	virtual void call() {
		return (object->*method)();
	}

private:
	Obj *object;
	void (Obj::*method)(void);
};
#endif 
