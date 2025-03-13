#ifndef PRODUCERCONSUMER_H
#define PRODUCERCONSUMER_H

#include "MessageQueue.h"

// Producer function
void producer(MessageQueue& messageQueue, int messageType, const std::string& payload);

// Consumer function
void consumer(MessageQueue& messageQueue);

#endif // PRODUCERCONSUMER_H
