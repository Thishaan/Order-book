#include "order.h"
#include <chrono>
class EventManager {

    // can maintain  this order for static casting 

enum class EventType {
    New_order,
    Order_filled,
    Order_cancelled,
    Order_partially_filled
};  

public:
EventManager(EventType type, Order order) : event_type{type}, order{order} {
    timestamp = std::chrono::system_clock::now();
}
private:

 std::chrono::time_point<std::chrono::system_clock> timestamp;
     EventType event_type;
     Order order; // The order associated with the event (if applicable)            



    
};