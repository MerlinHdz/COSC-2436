/** @file PlainBox.h */

#ifndef PLAIN_BOX_
#define PLAIN_BOX_

// Set the type of data stored in the box
//typedef double ItemType;

template<class ItemType> // Indicates this is a template definition // Change 1 to make this a template
// Declaration for the class PlainBox
class PlainBox : public BoxInterface<ItemType>
{
private:
    // Data field
    ItemType item;

public:
    // Default constructor
    PlainBox();

    // Parameterized constructor
    PlainBox(const ItemType& theItem);

    // Method to change the value of the data field
    virtual void setItem(const ItemType& theItem);

    // Method to get the value of the data field
    virtual ItemType getItem() const;
}; // end PlainBox

#include "PlainBox.cpp" // Include the implementation file // Change 2 to make this a template
#endif