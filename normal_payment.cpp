#include <iostream>
#include "Normal_payment.h"
#include <cmath>

using namespace std;

const float Normal_payment::eps = 0.001;

Normal_payment::type Normal_payment::pay() {
  cout << "Choose Payment type\n" << "1  Card\n" << "2  Cash\n" << "X  Exit\n";
  string tmp;
  cin >> tmp;
  if (tmp == "x" || tmp == "X") return FAIL;
  int choice = stoi(tmp);
  if (choice == 1) card();
  else if (choice == 2) cash();
  else return pay();
  cout << "Payment successful.\n\n";
  return static_cast<type>(choice); 
}

void Normal_payment::card() {
  cout << "Amount to pay: " << amount_due << "zl\n" << "Press enter to pay";
  cin.ignore();
  cin.get();
  drink.buy_drink();
  amount_due = 0;
}

void Normal_payment::cash() {
  cout << "Amount to pay: " << amount_due << "zl\n" 
  << "Available coins: 10gr, 20gr, 50gr, 1zl, 2zl, 5zl'\n";
  
  while (amount_due > (0 + eps)) {
    amount_due -= take_coin();
    if(amount_due > (0 + eps)) cout << "Amount left: " << amount_due << "zl\n";
  }

  while (amount_due < (0 - eps)) {
    float change = give_change();
    cout << "Given change: " << coin_to_string(change) << ", ";
    amount_due += change;
  }

  std::cout << '\n';
}

float Normal_payment::take_coin() {
  cout << "Insert coin: ";
  string tmp;
  cin >> tmp;
  if (tmp == "10gr") return 0.1f;
  else if (tmp == "20gr") return 0.2f;
  else if (tmp == "50gr") return 0.5f;
  else if (tmp == "1zl") return 1.0f;
  else if (tmp == "2zl") return 2.0f;
  else if (tmp == "5zl") return 5.0f;
  else return 0.0f;
}

float Normal_payment::give_change() {
  float amount = -amount_due + eps;
  if (amount >= 5) return 5.0f;
  else if (amount >= 2) return 2.0f;
  else if (amount >= 1) return 1.0f;
  else if (amount >= 0.5) return 0.5f;
  else if (amount >= 0.2) return 0.2f;
  else if (amount >= 0.1) return 0.1f;
  else return 0.0f;
}

string Normal_payment::coin_to_string(float change) {
  float amount = change + eps;
  if (amount >= 5.0f) return "5zl";
  else if (amount >= 2.0f) return "2zl";
  else if (amount >= 1.0f) return "1zl";
  else if (amount >= 0.5f) return "50gr";
  else if (amount >= 0.2f) return "20gr";
  else if (amount >= 0.1f) return "10gr";
  else return "unknown coin";
}

Normal_payment::Normal_payment(Drink& drink) : Payment(drink) { // Delegacja konstruktora e ramach LI
  amount_due = drink.get_price();
}
