#include <Arduino.h>
#include <Wire.h>
#include "lumiere.hpp"
#include "carbone.hpp"


// Pins de connexion pour les capteurs
const int pinCapteurLumiere = 39;
const int pinCapteurCO2 = 35;

// Instances des capteurs
CapteurLumiere capteurLumiere(pinCapteurLumiere);
CapteurCO2 capteurCO2(pinCapteurCO2);

void setup()
{
  Serial.begin(9600);                                                                                                                                                                                               Serial.begin(9600);
}

void loop()
{
  // Lecture de la valeur de luminosité
  int Luminosite = capteurLumiere.lireValeur();
  // Conversion de la valeur en pourcentage
  float valeurLumiere = (Luminosite / 4095.0) * 100.0;
  //Serial.print("Luminosite : ");
  //Serial.println(" %");

  // Lecture de la valeur de monoxyde de carbone
  int valeurCO2 = capteurCO2.lireValeur();
  //Serial.print("Concentration de CO2 : ");
  Serial.println(valeurCO2);
  Serial.println(valeurLumiere);
  //Serial.println("ppm");

  delay(3000);
}
