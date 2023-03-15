#pragma once
#include "payment.h"

class Free_payment: public Payment {
  public:
    virtual Payment::type pay() override;
    Free_payment(Drink& drink); 
};