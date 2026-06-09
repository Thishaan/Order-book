#include <cstdint>
#include <stdexcept> 
#include "../headers/Order.h"

Order::Order(Order::Order_Type type, Status status,
             std::uint64_t order_ID, float price, int quantity, int filled_quantity)
    : type{type}, status{status}, order_ID{order_ID}, price{price}, quantity{quantity}, filled_quantity{0} {}

void Order::cancel() {
    status = Status::Cancelled;
}


double Order::getPrice() const {
    return price;
}


Order::Order_Type  Order::getType()    const{
    return type;
}

void Order::fill(uint32_t amount){

    if(amount == 0){
        throw std::invalid_argument("Value out of percentage bounds");
    }
    if(amount >= quantity)
        status   = Status::Filled;
    else{

        status   = Status::Partially_filled;

    }
    filled_quantity =  amount; 
}


uint32_t Order::getFilledQuantity() const {
    return filled_quantity;
}

uint32_t Order::getQuantity() const{
    return quantity; 

}


Order::Status Order::getStatus() const{
    return status;
}

uint32_t Order::getRemainingQuantity() const{
    return quantity - filled_quantity; 
}