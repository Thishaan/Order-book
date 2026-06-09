#ifndef CONCURRENT_Q
#define CONCURRENT_Q

#include <queue>

template<typename T>
class ConcurrentQueue{


    private:
    std::queue<T>  m_queue;  // underlying queue
    std::mutex m_mutex;     // mutex for synchronizing access
    std::condition_variable m_cond_var; // condition variable for blocking pop when queue is empty

    public:
    ConcurrentQueue(); // default constructor
    T pop(); // returna copy of th frnt element ,removing it from the queue
    void push(const T& item); // jut add it on
    T & peak(); // return a reference to the front 


};