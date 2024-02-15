#ifndef KitchenTimerTM1637Display_h
#define KitchenTimerTM1637Display_h
#include <Arduino.h>
#include <TM1637Display.h>
#include <TimeCalculator.h>

enum class Dots {
    ON,
    OFF,
    BLINK
};

class KitchenTimerTM1637Display: public TM1637Display
{
public:
    KitchenTimerTM1637Display(int clk, int dio);

    Time displayKitchenTimer(long seconds, long minutes, long hours, long days);
    Time displayKitchenTimer(long seconds, long minutes, long hours);
    Time displayKitchenTimer(long seconds, long minutes);
    Time displayKitchenTimer(long seconds);

    void displayError();
    void displayDone();
    void displayAnimationSnake(int loops, int frameDelay);
    void displayAnimation4Square(int loops, int frameDelay);
    void displayAnimation2Square(int loops, int frameDelay);
    void displayAnimation1Square(int loops, int frameDelay);

    Dots dots = Dots::BLINK;
private:
    bool blink;
    const int SEG_DOTS = 0b01000000;
    TimeCalculator timeCalc;
};

#endif