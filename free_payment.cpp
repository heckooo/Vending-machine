#include <iostream>
#include "free_payment.h"

using namespace std;

Payment::type Free_payment::pay() {
  cout << "Your drink is sponsored by Silesian Univeristy of Technology\n";
  return Payment::CARD;
}

Free_payment::Free_payment(Drink& drink): Payment(drink) {

}