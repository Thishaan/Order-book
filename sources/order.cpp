#include <cstdint>

#include "../headers/Order.h"

Order::Order(Type type, Status status,
             std::uint64_t order_ID, float price, int quantity, int filled_quantity)
    : type{type}, status{status}, order_ID{order_ID}, price{price}, quantity{quantity}, filled_quantity{filled_quantity} {}

void Order::cancelOrder() {
    status = Status::Cancelled;
}

void Order::updateQuantity(int newQuantity) {
    quantity = newQuantity;
}

float Order::getPrice() const {
    return price;
}




