/** ADT stack: Array-based implementation 
 @file ArrayStack.h 
*/

#ifndef ARRAY_STACK_
#define ARRAY_STACK_

#include "StackInterface.h"

template<class ItemType>
class ArrayStack : public StackInterface<ItemType>
{
private:
    static const int DEFAULT_CAPACITY = 30;
    ItemType items[DEFAULT_CAPACITY]; // Array of stack items
    int top;    // Index to top of stack

public:
    ArrayStack();
    bool isEmpty() const;
    bool push(const ItemType& newEntry);
    bool pop();
    ItemType peek() const;
};  // end ArrayStack
#include "ArrayStack.cpp"
#endif