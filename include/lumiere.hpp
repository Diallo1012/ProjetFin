#include <Arduino.h>

// Classe pour le capteur de lumière
class CapteurLumiere {
  private:
    int pin;

  public:
    CapteurLumiere(int pin);
    ~CapteurLumiere();

    int lireValeur();
};