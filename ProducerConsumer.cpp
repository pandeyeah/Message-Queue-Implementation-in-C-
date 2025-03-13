#include "ProducerConsumer.h"
#include <iostream>

// Producer function
void producer(MessageQueue& messageQueue, int messageType, const std::string& payload) {
    Message message;
    message.messageType = messageType;
    message.payload = payload;

    messageQueue.enqueue(message);
    std::cout << "Producer: Message enqueued with type " << messageType << " and payload: " << payload << std::endl;
}

// Consumer function
void consumer(MessageQueue& messageQueue) {
    while (true) {
        Message message = messageQueue.dequeue();
        // Process the message
        std::cout << "Consumer: Message dequeued with type " << message.messageType << " and payload: " << message.payload << std::endl;
    }
}
