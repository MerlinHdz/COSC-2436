/**
 * @file LinkedList.h
*/
#ifndef LINKED_LIST_
#define LINKED_LIST_

#include "Node.h"
#include <vector>
#include <string>

class LinkedList
{
private:
    Node* headPtr;      // Pointer to the head of the list
    int numItems;       // Number of items in the list

public:
    // Constructor
    LinkedList();

    // Destructor
    ~LinkedList();

    // Copy constructor
    LinkedList(const LinkedList& other);

    // Public methods
    int getNumItems() const;
    void addNode(const std::string& category, const std::string& line);
    std::vector<std::string> toVector() const;
};

#include "LinkedList.cpp"
#endif
