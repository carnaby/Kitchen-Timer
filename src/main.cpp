#include <Arduino.h>
#include <KitchenTimerTM1637Display.h>

// display pins
#define CLK 2
#define DIO 3

#define TEST_DELAY 100

KitchenTimerTM1637Display display(CLK, DIO);

void setup()
{
    Serial.begin(9600);
    Serial.println("Program started!");
}

void loop()
{

    display.setBrightness(0);
    // display.dots = Dots::ON;    
    // display.dots = Dots::OFF;
    display.dots = Dots::BLINK;

    display.displayAnimation1Square(3, 30);
    display.displayAnimation2Square(3, 30);
    display.displayAnimation4Square(5, 30);
    display.displayAnimationSnake(5, 30);

    Time time = display.displayKitchenTimer(1,1,1,1);

    Serial.print("timedecimal ");
    Serial.println(time.timeDecimal);

    if (time.timeMode == TimeMode::DAYS){
        Serial.println("Time mode: DAYS");
    }
    if (time.timeMode == TimeMode::ERROR){
        Serial.println("Time mode: ERROR");
    }
    if (time.timeMode == TimeMode::HOURS){
        Serial.println("Time mode: HOURS");
    }
    if (time.timeMode == TimeMode::MINUTES){
        Serial.println("Time mode: MINUTES");
    }

    for (int k = 20; k >= 0; k--)
    {
        display.displayKitchenTimer(k);
        delay(TEST_DELAY);
    }
    
    delay(1000);

    for (int k = 80; k >= 0; k--)
    {
        display.displayKitchenTimer(k);
        delay(TEST_DELAY);
    }
    
    delay(1000);
    display.displayDone();
    delay(1000);
    display.displayError();
    delay(1000);
}
