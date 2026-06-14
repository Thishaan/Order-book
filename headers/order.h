#ifndef ORDER_HPP
#define ORDER_HPP

#include <cstdint>
#include <chrono>
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
          double price,
          int quantity,
          int filled_quantity);

    // Member functions
    // void cancelOrder();
    //void updateQuantity(int newQuantity);

    // Getters
    Order_Type  getType()              const;
    Status      getStatus()            const;
    uint64_t    getOrderID()           const;
    double      getPrice()             const;
    uint32_t    getQuantity()          const;
    uint32_t    getFilledQuantity()    const;
    uint32_t    getRemainingQuantity() const;

    // Actions
    void fill(uint32_t amount);
    void cancel();

private:
    Order_Type type;
    Status status;
    std::uint64_t order_ID;
    double price;
    uint32_t filled_quantity; // Track filled quantity for partial fills ONLY
    uint32_t quantity;
    std::chrono::time_point<std::chrono::steady_clock> timestamp;  // for priority

};

#endif // ORDER_HPP

