/**
 * 
 * OrderGenerator class
  - produces N orders per second
  - randomizes price around a midpoint (realistic drift)
  - randomizes buy/sell side
  - configurable speed, volume, price range
 */




template <typename T>
class OrderGenerate{


public:
    OrderGenerate();

private:
    
    std::uint32_t genRate; // number of orders per second
    void setGenRate () const;
    void generateOrders() const;
 
    
};