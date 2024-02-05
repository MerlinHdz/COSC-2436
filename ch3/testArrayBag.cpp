#include <iostream>
#include <string>
#include "ArrayBag.h"

using std::cout;
using std::endl;

void displayBag(ArrayBag<std::string>& bag)
{
    cout << "The bag contains " << bag.getCurrentSize()
         << " items." << endl;
    std::vector<std::string> bagItems = bag.toVector();

    int numberOfEntries = bagItems.size();
    for (int i = 0; i < numberOfEntries; i++)
    {
        cout << bagItems[i] << " ";
    }   // end for
    cout << endl << endl;
}   // end displayBag


void bagTester(ArrayBag<std::string>& bag)
{
    cout << "isEmpty: returns: " << bag.isEmpty() << " should be 1 (true)" << endl;
    displayBag(bag);

    std::string items[] = {"one", "two", "three", "four", "five", "one"};
    cout << "Adding 6 items to the bag. " << endl;
    for (int i = 0; i < 6; i++)
    {
        bag.add(items[i]);
    }   // end for

    displayBag(bag);

    cout << "isEmpty: returns " << bag.isEmpty()
         << "; should be 0 (false)" << endl;
    cout << "getCurrentSize: returns " << bag.getCurrentSize()
         << "; should be 6" << endl;
         
    cout << "Try to add another entry: add(\"extra\") returns "
         << bag.add("extra") << endl;
         
    cout << "contains \"one\" returns: " << bag.contains("one") << endl;
    cout << "getFrequencyOf \"one\" returns: " << bag.getFrequencyOf("one") << endl;

    cout << "Removing an item (\"three\")" << endl;
    bag.remove("three");
    displayBag(bag);
}   // end bagTester


// - - - - main - - - - //
int main()
{
    ArrayBag<std::string> bag;
    cout << "* * * * Testing the Array-Based Bag * * * * " << endl << endl;
    cout << "The initial bag is empty." << endl;
    bagTester(bag);
    cout << "All done!" << endl;

    return 0;
}   // end main