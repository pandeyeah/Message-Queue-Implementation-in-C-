#include "MessageQueue.h"

// Enqueue a message
void MessageQueue::enqueue(const Message& message) {
    std::unique_lock<std::mutex> lock(mutex_);
    queue_.push(message);
    lock.unlock();
    condition_.notify_one();
}

// Dequeue a message
Message MessageQueue::dequeue() {
    std::unique_lock<std::mutex> lock(mutex_);
    // Wait until a message is available
    condition_.wait(lock, [this] { return !queue_.empty(); });

    Message message = queue_.front();
    queue_.pop();
    return message;
}
