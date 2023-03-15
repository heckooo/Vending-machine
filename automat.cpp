#include <iostream>
#include "automat.h"

using namespace std;

void Automat::add_drink(std::string n, Drink::Category c, int a, float p, int al) {
  if (drinks.find(c) == drinks.end()) drinks[c] = vector<Drink>();
  drinks[c].push_back(Drink(n, c, a, p, al));
}

std::vector<Drink>& Automat::get_drinks(Drink::Category cat) {
  return drinks[cat];
}

Automat::Automat() {
  //Fizzy
  add_drink("Pepsi", Drink::fizzy, 330, 3, 15);
  add_drink("Pepsi", Drink::fizzy, 500, 4, 15);
  add_drink("Pepsi max", Drink::fizzy, 330, 3, 15);
  add_drink("Pepsi max", Drink::fizzy, 500, 4, 15);
  add_drink("7up", Drink::fizzy, 330, 3, 15);
  add_drink("7up", Drink::fizzy, 500, 4, 15);
  add_drink("Mirinda", Drink::fizzy, 330, 3, 15);
  add_drink("Mirinda", Drink::fizzy, 500, 4, 15);
  add_drink("Mountain Dew", Drink::fizzy, 330, 3, 15);
  add_drink("Mountain Dew", Drink::fizzy, 500, 4, 15);
  add_drink("Black", Drink::fizzy, 250, 3, 15);
  add_drink("Black Zero", Drink::fizzy, 250, 3, 15);
  add_drink("Monster", Drink::fizzy, 500, 6, 15);
  add_drink("Woda Gazowana", Drink::fizzy, 500, 3, 15);
  //Still
  add_drink("Capy Pomaranczowy", Drink::still, 330, 3, 15);
  add_drink("Capy Jablkowy", Drink::still, 330, 3, 15);
  add_drink("Tymbark Jablko Mieta", Drink::still, 200, 2.5, 15);
  add_drink("Tymbark Jablko Mieta", Drink::still, 500, 4, 15);
  add_drink("Tymbark Jablko Wisnia", Drink::still, 200, 2.5, 15);
  add_drink("Tymbark Jablko Wisnia", Drink::still, 500, 4, 15);
  add_drink("Lipton Green", Drink::still, 330, 3, 15);
  add_drink("Lipton Green", Drink::still, 500, 4, 15);
  add_drink("Lipton", Drink::still, 330, 3, 15);
  add_drink("Lipton", Drink::still, 500, 4, 15);
  //Hot
  add_drink("Espresso", Drink::hot, 30, 2, 10);
  add_drink("Podwojne Espresso", Drink::hot, 60, 3, 10);
  add_drink("Americano", Drink::hot, 180, 2.5, 10);
  add_drink("Americano", Drink::hot, 300, 3.5, 10);
  add_drink("Latte", Drink::hot, 180, 3, 10);
  add_drink("Latte", Drink::hot, 300, 4, 10);
  add_drink("Kawa bezkofeinowa", Drink::hot, 180, 3, 10);
  add_drink("Goraca Czekolada", Drink::hot, 180, 3, 10);
  add_drink("Goraca Czekolada", Drink::hot, 300, 4, 10);
  add_drink("Herbata", Drink::hot, 250, 3, 10);
  add_drink("Herbata Zielona", Drink::hot, 250, 3, 10);
}

float Automat::get_balance(Payment::type type) {
  switch(type) {
    case Payment::CARD:
      return a_balance;
    case Payment::CASH:
      return c_balance;
    default:
      return -1;
  }
}

void Automat::add_balance(Payment::type type, float amount) {
  switch(type) {
    case Payment::CARD:
      a_balance += amount;
      break;
    case Payment::CASH:
      c_balance += amount;
      break;
  }
}
