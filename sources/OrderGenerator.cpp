#include "../headers/OrderGenerator.hpp"
#include <stdint.h>
#include <ctime>

#include <random> // Include the standard random library


template <typename U> 
OrderGenerate<U>::OrderGenerate(){
       genRate = 4;
       orders =  null; 



       for(size_t i=0; i < genRate; i++){

        std::srand(std::time({}));

        std::random_device rd,rd_dub;
        std::mt19937 gen_64(rd());
        std::mt19937 dis_dub(rd_dub());

        // add a psuedo random for uint64 id, mans
        std::uniform_int_distribution<unsigned long long> dis(
        std::numeric_limits<std::uint64_t>::min(),
        std::numeric_limits<std::uint64_t>::max()
        );

        std::uniform_real_distribution<double> dis_dub(0.0 ,  500.0);
  
        int random_value = std::rand();
        int type  = std::rand();
        //int status  = std::rand();

        size_t quantity  = random_value % 50;
        

        Order order_curr(static_cast<Order_Type>(type %2),
          Status::New,
          dis(gen()),
          dis_dub(gen_dub())),
          quantity,
          0);

         

       }

}

template <typename U> 
void OrderGenerate<U>::setGenRate(uint32_t gen_rate) {
    gerRate =  gen_rate;
};