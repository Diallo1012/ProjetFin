#include <Arduino.h>
#include "lumiere.hpp"

    CapteurLumiere::CapteurLumiere(int pin)
    {
      this->pin = pin;
      pinMode(pin, INPUT);
    }
    CapteurLumiere::~CapteurLumiere(){}

    int CapteurLumiere::lireValeur(){

      return analogRead(pin);
    }