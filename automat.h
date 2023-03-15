#pragma once
#include <vector>
#include <map>
#include "drink.h"
#include "payment.h"

class Automat {
  std::map<Drink::Category, std::vector<Drink>> drinks;
  float c_balance = 0;
  float a_balance = 0;
  public:
    std::vector<Drink>& get_drinks(Drink::Category cat); // Referencja do calego wektora
    Automat();
    void add_drink(std::string n, Drink::Category c, int a, float p, int al);
    float get_balance(Payment::type type);
    void add_balance(Payment::type type, float amount);
};
