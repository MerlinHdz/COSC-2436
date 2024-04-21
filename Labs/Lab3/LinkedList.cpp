/**
 * @file LinkedList.cpp
 */
#include "LinkedList.h"
#include <iostream> // REMOVE

// Constructor
LinkedList::LinkedList() : headPtr(nullptr), numItems(0) {}

// Destructor
LinkedList::~LinkedList()
{
    while (headPtr != nullptr)
    {
        Node* temp = headPtr;
        headPtr = headPtr->getNext();
        delete temp;
    }
}

// Copy constructor
LinkedList::LinkedList(const LinkedList& other) : numItems(other.numItems)
{
    if (other.headPtr == nullptr)
    {
        headPtr = nullptr;
    }
    else
    {
        headPtr = new Node(*(other.headPtr));
        Node* current = headPtr;
        Node* otherCurrent = other.headPtr->getNext();

        while (otherCurrent != nullptr)
        {
            current->setNext(new Node(*(otherCurrent)));
            current = current->getNext();
            otherCurrent = otherCurrent->getNext();
        }
    }
}

// Accessor to get the number of items in the list
int LinkedList::getNumItems() const
{
    return numItems;
}

void LinkedList::addNode(const std::string& category, const std::string& line)
{
    Node* newNode = new Node();
    newNode->setCategory(category);
    newNode->setLine(line);

    // If the list is empty, add the new node as the head
    if (headPtr == nullptr)
    {
        headPtr = newNode;
    }
    else
    {
        Node* prev = nullptr;
        Node* current = headPtr;


        // Traverse the list -- Category of newNode is NOT in the list
        while (current != nullptr && category != current->getCategory())
        {
            prev = current;
            current = current->getNext();
        } // --

        while (current != nullptr && category == current->getCategory() && line > current->getLine())
        {
            prev = current;
            current = current->getNext();
        }

        //
        if (prev == nullptr)
        {
            std::cout << "Hello\n";
            newNode->setNext(headPtr);
            headPtr = newNode;
        }
        else
        {
            prev->setNext(newNode);
            newNode->setNext(current);
        }
    }

    numItems++;
}









// Convert linked list to vector
std::vector<std::string> LinkedList::toVector() const
{
    std::vector<std::string> result;
    Node* current = headPtr;

    while (current != nullptr)
    {
        result.push_back(current->getCategory());
        result.push_back(current->getLine());
        current = current->getNext();
    }

    return result;
}
