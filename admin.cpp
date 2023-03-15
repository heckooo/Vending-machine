#include <iostream>
#include "admin.h"
#include "menu.h"

using namespace std;

void Admin::launch() {
  if (!verify()) return;
  cout << "Choose action: \n" << "1  Balance \n" << "2 Change drinks quantity \n" << "X  Exit\n";
  string tmp;
  cin >> tmp;
  if (tmp == "X" || tmp == "x") return;
  switch(stoi(tmp)) {
    case 1:
      balance();
      break;
    case 2:
      set_quantity();
      break;
  }
}

bool Admin::verify() {
  cout << "Type Password: ";
  string tmp;
  cin >> tmp;
  if (tmp == "admin") return true;
  else {
    cout << "Wrong Password!\n";
    return false;
  }
}

void Admin::balance() {
  cout << "Card Balance: " << automat.get_balance(Payment::CARD);
  cout << "\nCash Balance: " << automat.get_balance(Payment::CASH) <<'\n';
}

void Admin::set_quantity() {
  cout << "Choose Drink Category\n" << "0  Fizzy Drinks\n" << "1  Still Drinks\n" << "3  Hot Drinks\n" << "X  Exit\n";
  string tmp;
  cin >> tmp;
  if (tmp == "X" || tmp == "x") return;
  int choice = stoi(tmp);
  Drink::Category cat = static_cast<Drink::Category>(choice);
  utils::print_drinks(automat, cat, true);
  cout << "Enter drink id to set quantity. Enter X to cancel.\n";
  cin >> tmp;
  if (tmp == "x" || tmp == "X") return;
  auto& drinks = automat.get_drinks(cat);
  int id = stoi(tmp);

  Drink& drink = automat.get_drinks(cat)[id];

  cout << "Enter new quantity: ";
  cin >> tmp;
  drink.set_quantity(stoi(tmp));
}

Admin::Admin(Automat& automat): automat(automat) {

}