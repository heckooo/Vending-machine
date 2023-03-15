#pragma once
#include "drink.h"

class Payment {
public:
  enum type {
    CARD = 1, CASH = 2, FAIL = 3
  };
  virtual type pay() = 0; // Polimorfizm
  Payment(Drink& drink) : drink(drink) { // Lista Inicjalizacyjna, po : - jaka zmienna skladowa klasy chcemy zainicjalizowac, a w () - argument, LI jest uzywana do const i referencji
  }
protected:
  Drink& drink;
};