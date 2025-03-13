#include <iostream>
#include <thread>
#include "MessageQueue.h"
#include "ProducerConsumer.h"

int main() {
    MessageQueue messageQueue;

    // Create producer and consumer threads
    std::thread producerThread(producer, std::ref(messageQueue), 1, "Hello, World!");
    std::thread consumerThread(consumer, std::ref(messageQueue));

    // Wait for threads to finish
    producerThread.join();
    consumerThread.join();

    return 0;
}
