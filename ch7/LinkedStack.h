/** ADT stack: Link-based implementation.
 @file LinkedStack.h 
*/

#ifndef LINKED_STACK_
#define LINKED_STACK_

#include "StackInterface.h"
#include "Node.h"

template<class ItemType>
class LinkedStack : public StackInterface<ItemType>
{
private:
    // This node contains the stack's top
    Node<ItemType>* topPtr; // Pointer to first node in the chain;
    
public:
    // Constructors and destructor
    LinkedStack(); // Default Constructor
    LinkedStack(const LinkedStack<ItemType>& aStack); // Copy constructor
    virtual ~LinkedStack(); // Destructor

    // Stack operations
    bool isEmpty() const;
    bool push(const ItemType& newItem);
    bool pop();
    ItemType peek() const;
};  // end LinkedStack

#include "LinkedStack.cpp"
#endif