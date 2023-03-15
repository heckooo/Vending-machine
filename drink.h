#pragma once
#include <string>

class Drink
{
public:
  enum Category
  {
    fizzy = 0,
    still = 1,
    hot = 2
  };
  void show_info(bool show_quantity);
  Drink(std::string n, Category c, int a, float p, int al);
  static std::string cat_to_string(Category cat);
  bool is_available();
  float get_price(); // Hermetyzacja danych - getr i setr. Do zmiennych skladowych nie mozna uzyskac dostepu bezposrednio, maja mozliwosc dokonania dodatkowego sprawdzenia, mozna zmienic implementacje, np uzyskanie ceny z innego zrodla
  void buy_drink();
  int get_quantity(); // Hermetyzacja danych
  void set_quantity(int quantity); // Hermetyzacja danych

private:
  Category cat; // Category
  std::string name;
  int cap; // Capacity
  float price;
  int amount_left;
};
