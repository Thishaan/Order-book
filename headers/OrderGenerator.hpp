
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

    T orders[genRate];


private:
    
    std::uint32_t genRate; // number of orders per second
    void setGenRate (uint32_t gen_rate);
    void generateOrders() const;
 
    
};