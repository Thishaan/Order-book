#include <cstdint>

#include "Order.h"

Order::Order(Type type, Status status,
             std::uint64_t order_ID, float price, int quantity)
    : type{type}, status{status}, order_ID{order_ID}, price{price}, quantity{quantity} {}

void Order::cancelOrder() {
    status = Status::Cancelled;
}

void Order::updateQuantity(int newQuantity) {
    quantity = newQuantity;
}

float Order::getPrice() const {
    return price;
}

