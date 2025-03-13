#ifndef MESSAGEQUEUE_H
#define MESSAGEQUEUE_H

#include <queue>
#include <mutex>
#include <condition_variable>
#include "Message.h"  // Include the Message structure

class MessageQueue {
public:
    // Enqueue a message
    void enqueue(const Message& message);

    // Dequeue a message
    Message dequeue();

private:
    std::queue<Message> queue_;
    std::mutex mutex_;
    std::condition_variable condition_;
};

#endif // MESSAGEQUEUE_H
