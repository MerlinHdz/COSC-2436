/**
 * @file usingArrayBag.cpp
 * @author Merlin Hernandez COSC-2436-005
 * @brief Menu driven program for testing the ArrayBag class and its methods
 * This program uses an integer bag (ArrayBag<int> bag)
 * User has the following menu options: 
 * 1. Display bag contents -- by calling bag.toVector() and then displaying that vector
 * 2. Add a value -- using bag.add(int anEntry)
 * 3. Remove a value -- using bag.remove(int anEntry)
 * 4. Sort bag -- using new method bag.bubbleSort()
 * 5. Search bag iterative -- using new method bag.binarySearch(int target)
 * 6. Search bag recursive -- using new method bag.binarySearchRecursive(int target)
 * - which calls a helper private function that performs the search.
 * 7. Exit -- exits the main loop
 * The menu will keep being displayed until user decides to exit by entering 7. 
 * Most of these menu options call functions that take care of user input, and then call
 * the actual method that perform the desired action.
 * 
 * An int bag is created in main, and partially filled with unique integer values.
 * Then the menu while loop begins.
 */

#include <iostream>
#include <string>
#include "ArrayBag.h"

using namespace std;

// ** Function prototypes
void bagTester(ArrayBag<int>& bag);
void displayBag(ArrayBag<int>& bag);
int getMenuOption();
void displayMenu();

void addToBag(ArrayBag<int>& bag);
void removeFromBag(ArrayBag<int>& bag);
void performSearch(ArrayBag<int>& bag);
void performSearchRecursive(ArrayBag<int>& bag);
// ** 

int main()
{
	// Array bag to hold integers
	ArrayBag<int> bag; // can hold 20 items

	// Array containing initial values to add to bag - 15 integers
	int anArray[] = {9, 4, 7, 1, 14, 23, 67, 99, -1, -5, 10, 55, 13, 35, 44};
	int numItems = sizeof(anArray) / sizeof(int);

	// Add  numbers to bag, do not fill completely
	for (int i = 0; i < numItems; i++)
	{
		bag.add(anArray[i]);
	} 


	bool isSorted = false; // flag to know if array is currently sorted
	int menuOption;
	menuOption = getMenuOption();

	while (menuOption != 7)
	{
		switch(menuOption)
		{
			case 1:
				displayBag(bag);
				break;
			case 2:
				addToBag(bag);
				isSorted = false;
				break;
			case 3:
				removeFromBag(bag);
				isSorted = false;
				break;
			case 4:
				bag.bubbleSort();
				cout << "\nBag sorted. \n\n";
				isSorted = true;
				break;
			case 5:
				if (isSorted)
					performSearch(bag);
				else
					cout << "\nBag must be sorted.\n\n";
				break;
			case 6:
				if (isSorted)
					performSearchRecursive(bag);
				else
					cout << "\nBag must be sorted.\n\n";
				break;
		}

		menuOption = getMenuOption(); // Take input for next iteration
	}

   return 0;   
}  // end main



/****************************************************************/
// Function:   bagTester
// Inputs:     the array bag
// Outputs:    none
// Purpose:    This function exercises some of the bag methods
/****************************************************************/
void bagTester(ArrayBag<int>& bag)
{
	cout << "The bag is not empty; isEmpty: returns " << bag.isEmpty() << endl;

	cout << "About to clear the bag, ";
	bag.clear();
   
	cout << "isEmpty: returns " << bag.isEmpty() << endl;
}  // end bagTester


/**
 * @brief Displays the bag's current size, stores bag.toVector() in vector bagItems
 * and displays items in that vector.
 * @param bag An integer ArrayBag
 * Output: None
 */
void displayBag(ArrayBag<int>& bag)
{
    cout << "\nThe bag contains " << bag.getCurrentSize()
         << " items." << endl;

    std::vector<int> bagItems = bag.toVector();

    int numberOfEntries = bagItems.size();
    for (int i = 0; i < numberOfEntries; i++)
    {
        cout << bagItems[i] << " ";
    }   // end for
    cout << endl << endl;
}   // end displayBag


/** 
 * @brief displays the menu options
 * Input: None
 * Output: None
 */
void displayMenu()
{
	cout << "1. Display bag contents\n";
	cout << "2. Add a value\n";
	cout << "3. Remove a value\n";
	cout << "4. Sort bag\n";
	cout << "5. Search bag iterative\n";
	cout << "6. Search bag recursive\n";
	cout << "7. Exit\n";
}


/** getMenuOption
 * @brief Get the Menu Option from user
 * Input: None
 * assumes user will provide an integer when prompted
 * @return int - the user's choice
 */
int getMenuOption()
{
	int choice = 0;
	displayMenu();

	// Get user input
	cout << "Enter your choice: ";
	cin >> choice;

	// Validate user input
	while (choice < 1 || choice > 7)
	{
		cout << "Invalid choice. Try again\n";
		cout << "Enter your choice: ";
		cin >> choice;
	}

	return choice;
} // end getMenuOption


/**
 * @brief Adds user provided int to an int bag
 * @param bag An integer ArrayBag
 * Output: None
 */
void addToBag(ArrayBag<int>& bag)
{
	int newInt;
	cout << "\nEnter integer to add: ";
	cin >> newInt;

	// Check that newInt is not already in bag (to ensure that each value is unique)
	if (!bag.contains(newInt))
	{
		if(bag.add(newInt))
			cout << newInt << " was added to the bag.\n\n";
		else
			cout << "Bag is full.\n\n";
	}
	else
		cout << newInt << " is already in the bag.\n\n";
}


/** removeFromBag
 * @brief Removes an int chosen by user from an int bag
 * takes user input, calls .remove() and message is displayed
 * to inform if successful or not
 * @param bag An int ArrayBag
 * Output: None
 */
void removeFromBag(ArrayBag<int>& bag)
{
	int toRemove;
	cout << "\nEnter integer you wish to remove: ";
	cin >> toRemove;

	if (bag.remove(toRemove))
		cout << toRemove << " was removed successfully.\n\n";
	else
		cout << "Integer was not removed.\n\n";
}


/**
 * @brief Performs iterative binary search
 * It takes user input (target) and calls bag.binarySearch(target)
 * Then displays a message to inform if found or not.
 * @param bag An int ArrayBag
 * Output: None
 */
void performSearch(ArrayBag<int>& bag)
{
	int target;
	cout << "\nEnter integer to search: ";
	cin >> target;

	// call binarySearch method form bag
	bool isPresent = bag.binarySearch(target);

	if (isPresent)
		cout << target << " is in the bag! (Iterative)\n\n";
	else
		cout << target << " was not found.\n\n";
}


/**
 * @brief Performs recursive binary search
 * It takes user input (target) and calls bag.binarySearchRecursive(target)
 * Then displays a message to inform if found or not.
 * @param bag 
 * Output: None
 */
void performSearchRecursive(ArrayBag<int>& bag)
{
	int target;
	cout << "\nEnter integer to search: ";
	cin >> target;

	// call  binarySearchRecursive method from bag
	bool isPresent = bag.binarySearchRecursive(target);

	if (isPresent)
		cout << target << " is in the bag! (Recursive)\n\n";
	else
		cout << target << " was not found.\n\n";
}