#include <Arduino.h>
#include <KitchenTimerTM1637Display.h>

KitchenTimerTM1637Display::KitchenTimerTM1637Display(int p1, int p2) : TM1637Display(p1, p2) {}

Time KitchenTimerTM1637Display::displayKitchenTimer(long seconds, long minutes, long hours, long days)
{
    long allSeconds = timeCalc.timeToSeconds(seconds, minutes, hours, days);
    return displayKitchenTimer(allSeconds);
}

Time KitchenTimerTM1637Display::displayKitchenTimer(long seconds, long minutes, long hours)
{
    long allSeconds = timeCalc.timeToSeconds(seconds, minutes, hours);
    return displayKitchenTimer(allSeconds);
}

Time KitchenTimerTM1637Display::displayKitchenTimer(long seconds, long minutes)
{
    long allSeconds = timeCalc.timeToSeconds(seconds, minutes);
    return displayKitchenTimer(allSeconds);
}

Time KitchenTimerTM1637Display::displayKitchenTimer(long seconds)
{
    Time time = timeCalc.secondsToTime(seconds);
    bool isDotsDisplayed = dots == Dots::ON ? true : dots == Dots::OFF ? false : blink;

    if (dots == Dots::BLINK) {
        blink = !blink;
    }

    if (time.timeMode == TimeMode::ERROR) {
        displayError();
        return time;
    }

    showNumberDecEx(time.timeDecimal, isDotsDisplayed ? SEG_DOTS : 0, true);
    return time;
}

void KitchenTimerTM1637Display::displayDone()
{
    const uint8_t segDone[] = {
        SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,          // d
        SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,  // O
        SEG_C | SEG_E | SEG_G,                          // n
        SEG_A | SEG_D | SEG_E | SEG_F | SEG_G           // E
    };
    setSegments(segDone);
}

void KitchenTimerTM1637Display::displayError()
{
    const uint8_t segDone[] = {
        SEG_A | SEG_D | SEG_E | SEG_F | SEG_G,          // E
        SEG_E | SEG_G,                                  // r
        SEG_E | SEG_G,                                  // r
        0x00                                            // _
    };
    setSegments(segDone);
}

void KitchenTimerTM1637Display::displayAnimationSnake(int loops, int frameDelay)
{
    const uint8_t frames[][4] = {
        { SEG_A, SEG_B, SEG_C, SEG_D },
        { SEG_B, SEG_C, SEG_D, SEG_E },
        { SEG_C, SEG_D, SEG_E, SEG_F },
        { SEG_D, SEG_E, SEG_F, SEG_A },
        { SEG_E, SEG_F, SEG_A, SEG_B },
        { SEG_F, SEG_A, SEG_B, SEG_C },
    };
    
    for (int l = 0; l < loops; ++l) {
        for (int i = 0; i < 6; ++i) {
            setSegments(frames[i]);
            delay(frameDelay);
        }
    }
}

void KitchenTimerTM1637Display::displayAnimation4Square(int loops, int frameDelay)
{
    const uint8_t frames[][4] = {
        { SEG_C, SEG_C, SEG_C, SEG_C },
        { SEG_D, SEG_D, SEG_D, SEG_D },
        { SEG_E, SEG_E, SEG_E, SEG_E },
        { SEG_F, SEG_F, SEG_F, SEG_F },
        { SEG_A, SEG_A, SEG_A, SEG_A },
        { SEG_B, SEG_B, SEG_B, SEG_B },
    };
    
    for (int l = 0; l < loops; ++l) {
        for (int i = 0; i < 6; ++i) {
            setSegments(frames[i]);
            delay(frameDelay);
        }
    }
}

void KitchenTimerTM1637Display::displayAnimation2Square(int loops, int frameDelay)
{
    const uint8_t frames[][4] = {
        { 0, SEG_A, SEG_A, 0 },
        { 0, SEG_B | SEG_DP, SEG_F, 0 },
        { 0, SEG_C | SEG_DP, SEG_E, 0 },
        { 0, SEG_D, SEG_D, 0 },
        { SEG_D, 0, 0, SEG_D },
        { SEG_E, 0, 0, SEG_C },
        { SEG_F, 0, 0, SEG_B },
        { SEG_A, 0, 0, SEG_A },
    };
    
    for (int l = 0; l < loops; ++l) {
        for (int i = 0; i < 8; ++i) {
            setSegments(frames[i]);
            delay(frameDelay);
        }
    }
}

void KitchenTimerTM1637Display::displayAnimation1Square(int loops, int frameDelay)
{
    const uint8_t frames[][4] = {
        { SEG_A, 0, 0, 0 },
        { 0, SEG_A, 0, 0 },
        { 0, 0, SEG_A, 0 },
        { 0, 0, 0, SEG_A },
        { 0, 0, 0, SEG_B },
        { 0, 0, 0, SEG_C },
        { 0, 0, 0, SEG_D },
        { 0, 0, SEG_D, 0 },
        { 0, SEG_D, 0, 0 },
        { SEG_D, 0, 0, 0 },
        { SEG_E, 0, 0, 0 },
        { SEG_F, 0, 0, 0 },
    };
    
    for (int l = 0; l < loops; ++l) {
        for (int i = 0; i < 12; ++i) {
            setSegments(frames[i]);
            delay(frameDelay);
        }
    }
}