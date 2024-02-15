#ifndef TimeCalculator_h
#define TimeCalculator_h
#include <Arduino.h>

enum class TimeMode {
    MINUTES,
    HOURS,
    DAYS,
    ERROR,
};

struct Time {
    long seconds;
    long minutes;
    long hours;
    long days;
    long timeDecimal;
    TimeMode timeMode;
};

class TimeCalculator
{
public:
    long timeToSeconds(long seconds, long minutes, long hours, long days);
    long timeToSeconds(long seconds, long minutes, long hours);
    long timeToSeconds(long seconds, long minutes);
    Time secondsToTime(long seconds);
};

#endif