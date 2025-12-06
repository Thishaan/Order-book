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

    enum class Type {
        Buy,
        Sell
    };

    // Constructor
    Order(Type type,
          Status status,
          std::uint64_t order_ID,
          float price,
          int quantity);

    // Member functions
    void cancelOrder();
    void updateQuantity(int newQuantity);

    float getPrice() const;

private:
    Type type;
    Status status;
    std::uint64_t order_ID;
    float price;
    int quantity;
};

#endif // ORDER_HPP

