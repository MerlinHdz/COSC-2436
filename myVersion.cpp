/**
 * @file LinkedList.cpp
 */
#include "LinkedList.h"

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

    if (headPtr == nullptr)
    {
        headPtr = newNode;
    }
    else
    {
        Node* current = headPtr;

        
        // Traverse to the end of the list
        while (current->getNext() != nullptr &&  current->getNext()->getCategory() == newNode->getCategory())
        {
            current = current->getNext();
        }
        
        // Add the new node
        newNode->setNext(current->getNext());
        current->setNext(newNode);
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




////
void LinkedList::addNode(const std::string& category, const std::string& line)
{
    Node* newNode = new Node();
    newNode->setCategory(category);
    newNode->setLine(line);

    // If the list is empty, add the new node as the head
    if (headPtr == nullptr)
    {
        headPtr = newNode;
        numItems++;
        return;
    }

    Node* prev = nullptr;
    Node* current = headPtr;

    // Traverse the list to find the correct position to insert the new node
    while (current->getNext() != nullptr && category != current->getCategory())
    {
        prev = current;
        current = current->getNext();
    }

    // If the category of the new node is the same as the current node's category,
    // insert the new node in ascending order based on the line
    while (current != nullptr && category == current->getCategory() && line > current->getLine())
    {
        prev = current;
        current = current->getNext();
    }

    // Insert the new node at the correct position
    if (prev == nullptr)
    {
        newNode->setNext(headPtr);
        headPtr = newNode;
    }
    else
    {
        prev->setNext(newNode);
        newNode->setNext(current);
    }

    numItems++;
}