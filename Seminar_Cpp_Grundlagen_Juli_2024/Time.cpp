#include <iostream>

#include "Time.h"

// 

void Time::setMilliseconds(int msecs)
{
    // Java
    milliseconds = msecs;
}



// constructors
Time::Time()
{
    m_hours = 0;
    m_minutes = 0;
    m_seconds = 0;
}


Time::Time(int hours, int minutes, int seconds)
{
    m_hours = 0;
    m_minutes = 0;
    m_seconds = 0;

    setHours(hours);
    setMinutes(minutes);
    setSeconds(seconds);
}

// getter / setter
int Time::getHours()
{
    return m_hours;
}

void Time::setHours(int hours)
{
    if (hours >= 0 && hours < 24) {

        m_hours = hours;
    }
    // ignore wrong value
    // silent error recovery
}

int Time::getMinutes()
{
    return m_minutes;
}

void Time::setMinutes(int minutes)
{
    if (minutes >= 0 && minutes < 60) {

        m_minutes = minutes;
    }
    // ignore wrong value
    // silent error recovery
}

int Time::getSeconds()
{
    return m_seconds;
}

void Time::setSeconds(int seconds) 
{
    if (seconds >= 0 && seconds < 60) {

        m_seconds = seconds;
    }
    // ignore wrong value
    // silent error recovery
}




void Time::reset()
{
    m_hours = 0;
    m_minutes = 0;
    m_seconds = 0;
}

void Time::print()
{
    std::printf("%02d:%02d:%02d\n", m_hours, m_minutes, m_seconds);
}

void Time::increment()
{
    // to be done
}
