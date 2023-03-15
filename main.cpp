#include <iostream>
#include "automat.h"
#include "menu.h"
#include "Normal_payment.h"
#include "Free_payment.h"

using namespace std;

int main() {
    auto automat = Automat();
    auto menu = Menu<Normal_payment, Free_payment>(automat);
    menu.loop();
    return 0;
}
