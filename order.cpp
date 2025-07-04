#include <iostream>
#include <cstdint>

class Order{


private:

Type type;
Status status;
uint64_t order_ID;
float price;
int quantity;

public:
class enum Status{New, Filled, Cancelled, Partially_filled};
class enum Type{Buy, Sell};

Order(Type type, Status status,uint64_t order_ID, float price, int quantity): type{type}, status{status}, order_ID{order_ID}, price{price}, quantity{quantity}
{

}

void cancelOrder(){
  this->status= Cancelled; 
};



void updateQuantity(int newQuantity){

this->quantity =  newQuantity;
};

float getPrice(){
   return this->price;
};

}
