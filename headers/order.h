#ifndef ORDER_HPP
#define ORDER_HPP

#include <cstdint>

class Order {
public:
    // Enums must be declared *inside* the class, not as "class enum"
    enum class Status {
        New,
        Filled,
        Cancelled,
        Partially_filled
    };

    enum class Order_Type {
        Buy,
        Sell
    };

    // Constructor
    Order(Order_Type type,
          Status status,
          std::uint64_t order_ID,
          float price,
          int quantity,
          int filled_quantity);

    // Member functions
    void cancelOrder();
    void updateQuantity(int newQuantity);

    float getPrice() const;

private:
    Order_Type type;
    Status status;
    std::uint64_t order_ID;
    float price;
    int filled_quantity; // Track filled quantity for partial fills ONLY
    int quantity;
};

#endif // ORDER_HPP

