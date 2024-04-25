/** ADT Queue: ADT List Implementation.
 @file ListQueue.h */

#ifndef LIST_QUEUE_
#define LIST_QUEUE_

#include "QueueInterface.h"
#include "LinkedList.h"
#include "PrecondViolatedExcept.h"
#include <memory>

template<class ItemType>
class ListQueue : public QueueInterface<ItemType>
{
private:
    std::unique_ptr<LinkedList<ItemType>> listPtr; // Pointer to list of queue items

public:
    ListQueue();
    ListQueue(const ListQueue& aQueue);
    ~ListQueue();

    bool isEmpty() const;
    bool enqueue(const ItemType& newEntry);
    bool dequeue();

    /** @throw PrecondViolatedExcept if this queue is empty. */
    ItemType peekFront() const;
};
#include "ListQueue.cpp"
#endif