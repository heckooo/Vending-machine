#include <iostream>
#include "drink.h"

using namespace std;

void Drink::show_info(bool show_quantity) {    // For user (admin will extend)
  string am;
  if (show_quantity) am = to_string(amount_left);
  else am = !is_available() ? "Unavailable" : "";
  cout<<name<<" "<<cap<<"ml"<<" "<<price<<"zl "<< am <<"\n";
}

Drink::Drink(string n, Category c, int a, float p, int al) {
  name = n;
  cat = c;
  cap = a;
  price = p;
  amount_left = al;
}

bool Drink::is_available() {
  return amount_left != 0;
}

string Drink::cat_to_string(Category cat) {
  switch(cat) {
    case fizzy:
      return "fizzy";
    case still:
      return "still";
    case hot:
      return "hot";
    default:
      return "unknown";
  }
}

float Drink::get_price() {
  return price;
}

void Drink::buy_drink() {
  amount_left = amount_left - 1;
}

int Drink::get_quantity() {
  return amount_left;
}

void Drink::set_quantity(int quantity) {
  amount_left = quantity;
}
