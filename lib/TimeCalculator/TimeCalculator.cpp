#include <Arduino.h>
#include <TimeCalculator.h>

long TimeCalculator::timeToSeconds(long seconds, long minutes, long hours, long days)
{
    return timeToSeconds(seconds, minutes, hours + (days * 24L));
}

long TimeCalculator::timeToSeconds(long seconds, long minutes, long hours)
{
    return timeToSeconds(seconds, minutes + (hours * 60L));
}

long TimeCalculator::timeToSeconds(long seconds, long minutes)
{
    return seconds + (minutes * 60L);
}

Time TimeCalculator::secondsToTime(long seconds)
{
    Time time;

    time.days = seconds / (60L * 60L * 24L);
    seconds -= time.days * (60L * 60L * 24L);

    time.hours = seconds / (60L * 60L);
    seconds -= time.hours * (60L * 60L);

    time.minutes = seconds / 60L;
    seconds -= time.minutes * 60L;

    time.seconds = seconds;

    if (time.days > 99 || time.days < 0 || time.hours < 0 || time.minutes < 0 || time.seconds < 0) {
        time.timeMode = TimeMode::ERROR;
        return time;
    }

    if (time.days > 0) {
        time.timeDecimal = time.days * 100 + time.hours;
        time.timeMode = TimeMode::DAYS;
        return time;
    }

    if (time.hours > 0) {
        time.timeDecimal = time.hours * 100 + time.minutes;
        time.timeMode = TimeMode::HOURS;
        return time;
    }

    time.timeDecimal = time.minutes * 100 + time.seconds;
    time.timeMode = TimeMode::MINUTES;
    return time;
}

