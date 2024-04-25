/** ADT queue: Link-based implementation 
 @file QueueLinked.h */

#ifndef LINKED_QUEUE_
#define LINKED_QUEUE_

#include "QueueInterface.h"
#include "Node.h"
#include <memory>

template<class ItemType>
class LinkedQueue: public QueueInterface<ItemType>
{
private:
    // The queue is implemented as a chain of linked nodes that has
    // two external pointers, a head pointer for the front of the queue
    // and a tail pointer for the back of the queue.
    std::shared_ptr<Node<ItemType>> fontPtr;
    std::shared_ptr<Node<ItemType>> backPtr;

public:
    LinkedQueue()
    LinkedQueue(const LinkedQueue& aQueue);
    ~LinkedQueue();

    bool isEmpty() const;
    bool enqueue(const ItemType& newEntry);
    bool dequeue();

    ItemType peekFront() const;
};

#include "LinkedQueue.cpp"
#endif