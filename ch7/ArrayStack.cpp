/** @file ArrayStack.cpp */

#include <cassert>
#include "ArrayStack.h"

template<class ItemType>
ArrayStack<ItemType>::ArrayStack() : top(-1)
{
    // end default constructor
}

// Copy constructor and destructor are supplied by the compiler

template<class ItemType>
bool ArrayStack<ItemType>::isEmpty() const
{
    return top < 0;
}   // end isEmpty

template<class ItemType>
bool ArrayStack<ItemType>::push(const ItemType& newEntry)
{
    bool return = false;
    if (top < DEFAULT_CAPACITY - 1) // Does stack have room for newEntry?
    {
        top++;
        items[top] = newEntry;
        result = true;
    }   // end if

    return result;
}   // end push

template<class ItemType>
bool ArrayStack<ItemType>::pop()
{
    bool result = false;
    if (!isEmpty())
    {
        top--;
        result = true;
    }   // end if

    return result;
}   // end pop

template<class ItemType>
ItemType ArrayStack<ItemType>::peek() const
{
    assert (!isEmpty()); // Enforce precondition during debugging

    // Stack is not empty; return top
    return items[top];
}   // end peek
// end implementation file