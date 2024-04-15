#include <iostream>
using namespace std;

class Node
{
	private:
		int item;
		Node* next;
	public:
		Node();
		int getItem();
		Node* getNext();
		void setItem(int);
		void setNext(Node*);
};

Node::Node()
{ next = nullptr; }

int Node::getItem()
{ return item; }

Node* Node::getNext()
{ return next; }

void Node::setItem(int i)
{ item = i; }

void Node::setNext(Node* n)
{ next = n; }

const int QUIT = 4;

int getValidMenuOption();
void add(Node* &);
void remove(Node* &);
void remove2(Node* &);
void display(Node*);

int main()
{
	int option;
	Node* headPtr = nullptr;
	
	option = getValidMenuOption();
	while (option != QUIT)
	{
		switch (option)
		{
			case 1:
				add(headPtr);
				break;
			case 2:
				remove2(headPtr);
				break;
			case 3:
				display(headPtr);
				break;
		}
		option = getValidMenuOption();
	}
	
	return 0;
}

int getValidMenuOption()
{
	int option;
	
	cout << "\n1. Add\n"
	     << "2. Remove\n"
	     << "3. Display\n"
	     << "4. Quit\n";
	cout << "Enter option: ";
	cin >> option;
	
	while (option < 1 || option > QUIT)
	{
		cout << "Invalid option - try again\n";
		cin >> option;
	}
	
	return option;
}

void add(Node* &startPtr)
{
	int num;
	Node* newNodePtr = nullptr;
	
	cout << "Enter an integer: ";
	cin >> num;
	
	newNodePtr = new Node();
	newNodePtr->setItem(num);
	
	newNodePtr->setNext(startPtr);
	startPtr = newNodePtr;
	
	cout << "just added " << startPtr->getItem() << endl;
	cout << "In add startPtr is " << startPtr << endl;
}

void remove(Node* &startPtr)
{
	Node* curPtr = startPtr;
	Node* nodeToDeletePtr = nullptr;
	int removeValue;
	bool found = false;
	
	cout << "Enter value to remove: ";
	cin >> removeValue;
		
	while (!found && curPtr)
	{
		if (removeValue == curPtr->getItem())
			found = true;
		else
			curPtr = curPtr->getNext();
	}
		
	if (found)
	{
		curPtr->setItem(startPtr->getItem());
		nodeToDeletePtr = startPtr;
		startPtr = startPtr->getNext();
		
		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;
		
		cout << removeValue << " has been removed\n";
	}
	else
		cout << removeValue << " was not in the list\n";
}

void remove2(Node* &startPtr)
{
	Node* prevPtr = startPtr;
	Node* nodeToDeletePtr = nullptr;
	int removeValue;
	bool found = false;
	
	cout << "Enter value to remove: ";
	cin >> removeValue;
		
	while (!found && prevPtr)
	{
		if (removeValue == prevPtr->getNext()->getItem())
			found = true;
		else
			prevPtr = prevPtr->getNext();
	}
		
	if (found)
	{
		nodeToDeletePtr = prevPtr->getNext();
		prevPtr->setNext(nodeToDeletePtr->getNext());
		
		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;
		
		cout << removeValue << " has been removed\n";
	}
	else
		cout << removeValue << " was not in the list\n";
}

void display(Node* startPtr)
{
	Node* curPtr = startPtr;
	
	cout << "\nThe list is: \n";
	
	if (!startPtr)
		cout << "The list is EMPTY\n";
		
	while (curPtr)
	{
		cout << curPtr->getItem() << "  ";
		curPtr = curPtr->getNext();
	}
	cout << endl << endl;
}