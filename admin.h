#pragma once
#include "automat.h"

class Admin {
  Automat& automat;
  bool verify();
  void balance();
  void set_quantity();
public:
  void launch();
  Admin(Automat& automat);
};
