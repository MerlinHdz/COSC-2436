/** @file StackInterface.h */
#ifndef STACK_INTERFACE_
#define STACK_INTERFACE_

template<class ItemType>
class StackInterface
{
public:
    /**
     * @brief Sees whether the stack is empty
     * @return True if the stack is empty, false if not. */
    virtual bool isEmpty() const = 0;

    /**
     * @brief Adds a new entry to the top of the stack.
     * @post If operation is successful, newEntry is at the top of the stack
     * @param newEntry The object to be added as a new entry
     * @return True if the addition is successful, false if not.
     */
    virtual bool push(const ItemType& newEntry) = 0;

    /**
     * @brief Removes the top of this stack
     * @post If the operation was successful, the top of the stack has been removed
     * @return True if the removal was successful, false if not
     */
    virtual bool pop() = 0;

    /**
     * @brief Returns a copy of the top of this stack
     * @pre The stack is not empty
     * @post A copy of the top of the stack has been returned, and the stack is unchanged.
     * @return a copy of the top of the stack
     */
    virtual ItemType peek() const = 0;

    /**
     * @brief Destroys this stack and frees its assigned memory */
    virtual ~StackInterface() {}
    // end StackInterface
};
#endif