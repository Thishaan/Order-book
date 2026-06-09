#include "ConccurrentQueue.hpp"

template<typename T>
ConcurrentQueue<T>::ConcurrentQueue() {
    // Initialize any necessary members if needed
    this->m_queue = std::queue<T>(); // Initialize the underlying queue

}


template <typename T>
T ConcurrentQueue<T>::pop() {
    // Implement thread-safe pop operation




}


template <typename T>
void ConcurrentQueue<T>::push(const T& item) {
    // Implement thread-safe push operation
}



template <typename T>
T & ConcurrentQueue<T>::peak() {
    // Implement thread-safe peak operation


  
    return m_queue.front();
}