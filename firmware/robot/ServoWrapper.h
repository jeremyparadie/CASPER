#ifndef ServoWrapper_h
#define ServoWrapper_h

#include <Wire.h>
#include "src/Adafruit-PWM-Servo-Driver/Adafruit_PWMServoDriver.h"
#include "Arduino.h"                  //Standard arduino library

class ServoWrapper{                   //Wrapper class for the ____ library- this will make it much easier to work with the ____
  private:                            //Private- can't access these directly
    unsigned long errorCount=0;        //The number of errors since program start or since errors have been wiped
    String lastError="All good; No errors!";//The default error message, to be replaced with errors when they occur
    Adafruit_PWMServoDriver PCA9685;             //The ____ object from the ____ library, which this class is wrapping. 
    String checkForTransmissionErrors(String functionName);
    float checkServoVoltage(String functionName);
    int angleOfServo[8]={1000,1000,1000,1000,1000,1000,1000,1000};
    const int pulseMin=164; //minimum pulse length out of 4096
    const int pulseMax=564; //maximum pulse length out of 4096
    
  public:                             //Public- feel free to use these
    ServoWrapper();                   //Constructor- gets called automatically when you make an object from this class
    void initialize();                //Call this once before you use any of the other functions below. Configures ____ settings.
    String clearErrors();             //Replaces the error with "All good; No errors!" and sets errorCount to 0.
    String getLastError();            //Returns the last error that occured (string)
    String getErrorCount();           //Returns the number of errors that have occured since the program start or since clearErrors() was called (string)
    String getAngle(byte pin);
    String setAngle(byte pin,String angle);
    String goLimp(byte pin);
    String getVoltage();
    float floatMap(float x, float in_min, float in_max, float out_min, float out_max);
    
};

#endif
