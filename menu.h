#pragma once
#include <iostream>
#include <string>
#include "drink.h"
#include "automat.h"
#include "payment.h"
#include "admin.h"
#include <memory>

namespace utils {
  inline void print_drinks(Automat& automat, Drink::Category cat, bool show_quantity = false) {
  std::cout << "Drink Category: " << Drink::cat_to_string(cat) << '\n';
  auto& drinks = automat.get_drinks(cat);
  for (int i = 0; i < drinks.size(); i++) {
    std::cout << i << "  ";
    drinks[i].show_info(show_quantity);
   } 
}};

template <typename everyone, typename employee> // Szablon klasy - w zaleznosci tego co podamy jako argumenty szablonu, kompilator wygeneruje odrebne warianty tej klasy
class Menu {
  void take_action(int choice) {
  if (choice == 3) return admin.launch();
  Drink::Category cat = static_cast<Drink::Category>(choice); //Przekonwertowanie int na Category
  utils::print_drinks(automat, cat);
  buy_drink(cat);
}
  void print_menu() {
  std::cout << "Available actions: " << '\n';
  std::cout << "0  Fizzy Drinks" << '\n';
  std::cout << "1  Still Drinks" << '\n';
  std::cout << "2  Hot Drinks" << '\n';
  std::cout << "3  Administrator" << '\n';
  std::cout << "X  Exit" << '\n';
}

  void buy_drink(Drink::Category cat) {
  std::cout << "Enter drink id to buy. Enter X to cancel.\n";
  std::string tmp;
  std::cin >> tmp;
  if (tmp == "x" || tmp == "X") return; //Powrot do loop
  if (cat == Drink::hot) get_sugar();
  auto& drinks = automat.get_drinks(cat);
  int id = std::stoi(tmp);
  if (!drinks[id].is_available()) {
    std::cout << "Drink not available!\n";
    return;
  }
  auto payment = get_payment(drinks[id]);
  Payment::type type = payment->pay(); //Przekierwanie do platnosci
  automat.add_balance(type, drinks[id].get_price());
}
  Automat& automat;
  Admin admin;
  void get_sugar() {
  std::cout << "How much sugar? (0-5): ";
  int sugar;
  std::cin >> sugar;
  if (sugar < 0 || sugar > 5) return get_sugar();
  std::cout << sugar << " spoons of Sugar\n";
}

std::unique_ptr<Payment> get_payment(Drink& drink) { // Zwraca wskaznik do payment; Wskaznik Inteligentny (jesli wyjdzie poza zakres to usunie payment)
  std::cout << "Are you a University employee? Y/N: ";
  std::string tmp;
  std::cin >> tmp;
  if (tmp == "n" || tmp == "N") return std::make_unique<everyone>(drink); // Polimorfizm, szablon
  else if (tmp == "y" || tmp == "Y") return std::make_unique<employee>(drink); // Polimorfizm, szablon
  else return get_payment(drink);
}

  public:
  void loop() {
  while (true) {
    print_menu();
    std::string tmp;
    std::cin >> tmp;
    if (tmp == "x" || tmp == "X") break;
    int choice = std::stoi(tmp);
    take_action(choice);
  }
}
  
  Menu(Automat& aut): automat(aut), admin(aut) {
  
}
};