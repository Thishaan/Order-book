#include "ConccurrentQueue.hpp"

template<typename T>
ConcurrentQueue<T>::ConcurrentQueue() {
    // Initialize any necessary members if needed
    this->m_queue = std::queue<T>(); // Initialize the underlying queue

}


template <typename T>
T ConcurrentQueue<T>::pop() {
    // Implement thread-safe pop operation
      if (m_queue.empty()) {

         m_cond_var.wait( m_mutex, [this](){ return !m_queue.empty(); } );
       // throw std::runtime_error("Queue is empty, CANNOT POP");
    }

    std::lock_guard<std::mutex> lock(m_mutex); // Lock the mutex to ensure thread safety
    T item = m_queue.front(); // Get the front item
    m_queue.pop(); // Remove the item from the queue
    return item; // Return the popped item
}


template <typename T>
void ConcurrentQueue<T>::push(const T& item) {
    // Implement thread-safe push operation
    std::lock_guard<std::mutex> lock(m_mutex); // Lock the mutex to ensure thread safety
    m_queue.push(item); // Add the item to the queue
    m_cond_var.notify_one();
}



template <typename T>
T & ConcurrentQueue<T>::peak() {

    // Implement thread-safe peak operation
    if (m_queue.empty()) {
        m_cond_var.wait( m_mutex, [this](){ return !m_queue.empty(); } );
        // throw std::runtime_error("Queue is empty, CANNOT PEAK");
    }
    std::lock_guard<std::mutex> lock(m_mutex); // Lock the mutex to ensure thread safety
    return m_queue.front();
}


