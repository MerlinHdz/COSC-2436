#include <iostream>
#include <memory>

using namespace std;

class Node
{
	private:
		int item;
		shared_ptr<Node> next;
	public:
		Node();
		int getItem();
		shared_ptr<Node> getNext();
		void setItem(int);
		void setNext(shared_ptr<Node>);
};

Node::Node()
{ next = nullptr; }
int Node::getItem()
{ return item; }
shared_ptr<Node> Node::getNext()
{ return next; }
void Node::setItem(int i)
{ item = i; }
void Node::setNext (shared_ptr<Node> n)
{ next = n; }

const int QUIT = 4;

int getValidMenuOption();
void add(shared_ptr<Node> &);
void remove(shared_ptr<Node> &);
void remove2(shared_ptr<Node> &);
void display(shared_ptr<Node>);

int main()
{
	int option;
	shared_ptr<Node> headPtr = nullptr;
	
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

void add(shared_ptr<Node> &startPtr)
{
	int num;
	shared_ptr<Node> newNodePtr;
	
	cout << "Enter an integer: ";
	cin >> num;
	
	newNodePtr = make_shared<Node>();
	newNodePtr->setItem(num);
	
	newNodePtr->setNext(startPtr);
	startPtr = newNodePtr;

}

void remove(shared_ptr<Node> &startPtr)
{
	shared_ptr<Node> curPtr = startPtr;
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
		startPtr = startPtr->getNext();
		
		cout << removeValue << " has been removed\n";
	}
	else
		cout << removeValue << " was not in the list\n";
}

void remove2(shared_ptr<Node> &startPtr)
{
	shared_ptr<Node> prevPtr = startPtr;
	int removeValue;
	bool found = false;
	
	cout << "Enter value to remove: ";
	cin >> removeValue;
		
	if (removeValue == startPtr->getItem())
	{
		startPtr = startPtr->getNext();	
		cout << removeValue << " has been removed\n";	
	}
	else
	{
		while (!found && prevPtr)
		{
			if (removeValue == prevPtr->getNext()->getItem())
				found = true;
			else
				prevPtr = prevPtr->getNext();
		}
			
		if (found)
		{
			prevPtr->setNext(prevPtr->getNext()->getNext());
			
			cout << removeValue << " has been removed\n";
		}
		else
			cout << removeValue << " was not in the list\n";
	}
}

void display(shared_ptr<Node> startPtr)
{
	shared_ptr<Node> curPtr = startPtr;
	
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