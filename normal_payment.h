#pragma once
#include "drink.h"
#include "payment.h"
#include <string>

class Normal_payment: public Payment {
public:
  virtual Payment::type pay() override; // Nadpisanie funkcji z klasy bazowej
  Normal_payment(Drink& drink);
private:  
  void cash();
  void card();
  float amount_due;
  static const float eps;
  float take_coin();
  float give_change();
  std::string coin_to_string(float change);
};
