
 #include <stdint.h>


/**
 * 
 * OrderGenerator class
  - produces N orders per second
  - randomizes price around a midpoint (realistic drift)
  - randomizes buy/sell side
  - configurable speed, volume, price range
 */


template <typename U>
class OrderGenerate{


public:
    OrderGenerate();

    U * orders[genRate];


private:
    
    uint32_t genRate{4}; // number of orders per second
    void setGenRate (uint32_t gen_rate);
    void generateOrders();

    void publish_order();
 
    
};