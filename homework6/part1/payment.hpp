#ifndef PAYMENT_H
#define PAYMENT_H

#include "customer.h"
#include <string>

class Payment {
private:
  std::string cardNumber;
  std::string payType

public:
  Payment();
  Payment(std::string cardNumber, std::string payType);
  // card information
  std::string getCardNumber();
  std::string setPayType();
  std::string getPayType();
  // put in card information
  void setCardNumber(std::string cardNumber);
  // make the transaction using the cardnumber
  void makePayment(std::string cardNumber);
};

#endif