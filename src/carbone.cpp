#include <Arduino.h>
#include "carbone.hpp"

    CapteurCO2::CapteurCO2(int pin)
    {
      this->pin = pin;
      pinMode(pin, INPUT);
    }
    CapteurCO2::~CapteurCO2(){}

    int CapteurCO2::lireValeur(){
        
      return analogRead(pin);
    }