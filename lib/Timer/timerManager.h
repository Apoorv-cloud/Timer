#ifndef TIMERMANAGER_H
#define TIMERMANAGER_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#ifndef NULL
#define NULL 0
#endif

#include "timer.h"

class TimerManager {
  friend class Timer;

public:
  static TimerManager& instance();
  void update();
	void start();
	void stop();
	void pause();
	void reset();

private:
  TimerManager();
  TimerManager(TimerManager const &);
  void operator=(TimerManager const &);
  void add(Timer *timer);
  bool remove(Timer *timer);
  class TimerNode {
  public:
    TimerNode(Timer *timer) {
      next = NULL;
      value = timer;
    }
    TimerNode *next;
    Timer *value;
  };

  TimerNode *first;
  TimerNode *last;
};
#endif 