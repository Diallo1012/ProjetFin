#include <Arduino.h>

// Classe pour le capteur de lumière
class CapteurCO2 {
  private:
    int pin;

  public:
    CapteurCO2(int pin);
    ~CapteurCO2();

    int lireValeur();
};
