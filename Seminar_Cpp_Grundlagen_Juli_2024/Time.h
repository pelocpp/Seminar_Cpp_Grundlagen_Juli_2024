#pragma once

class Time
{
private:
    // member data / instance variables
    int m_hours;
    int m_minutes;
    int m_seconds;

    int milliseconds;

public:
    void setMilliseconds(int milliseconds);

public:
    // Konstruktoren // constructor(s)
    Time();  // default c'tor
    Time(int hours, int minutes, int seconds);


public:
    // getter / setter
    int getHours();
    void setHours(int hours);

    int getMinutes();
    void setMinutes(int minutes);

    int getSeconds();
    void setSeconds(int seconds);

public:
    // public interface / methods
    void reset();
    void increment();
    void print();

    // Vergleich zweier Uhrzeiten
    bool equals(const Time& other) const;
};
