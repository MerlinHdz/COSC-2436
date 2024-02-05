#include "ArrayBag.h"
#include <iostream>
#include <cstddef>


template<class ItemType>
ArrayBag<ItemType>::ArrayBag(): itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}  // end default constructor


template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize


template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty


template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry)
{
	bool hasRoomToAdd = (itemCount < maxItems);
	if (hasRoomToAdd)
	{
		items[itemCount] = newEntry;
		itemCount++;
	}  // end if
    
	return hasRoomToAdd;
}  // end add


template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
{
   int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
	if (canRemoveItem)
	{
		itemCount--;
		items[locatedIndex] = items[itemCount];
	}  // end if
    
	return canRemoveItem;
}  // end remove


template<class ItemType>
void ArrayBag<ItemType>::clear()
{
	itemCount = 0;
}  // end clear


template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
   int frequency = 0;
   int curIndex = 0;       // Current array index
   while (curIndex < itemCount)
   {
      if (items[curIndex] == anEntry)
      {
         frequency++;
      }  // end if
      
      curIndex++;          // Increment to next entry
   }  // end while
   
   return frequency;
}  // end getFrequencyOf


template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
	return getIndexOf(anEntry) > -1;
}  // end contains

/* ALTERNATE 1: First version
template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& target) const 
{
   return getFrequencyOf(target) > 0;
}  // end contains

// ALTERNATE 2: Second version 
template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
   bool found = false;
   int curIndex = 0;        // Current array index
   while (!found && (curIndex < itemCount))
   {
      if (anEntry == items[curIndex])
      {
         found = true;
      } // end if
      
      curIndex++;           // Increment to next entry
   }  // end while   
   
   return found;
}  // end contains
*/


template<class ItemType>
std::vector<ItemType> ArrayBag<ItemType>::toVector() const
{
   std::vector<ItemType> bagContents;
	for (int i = 0; i < itemCount; i++)
		bagContents.push_back(items[i]);
      
   return bagContents;
}  // end toVector


// private
template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{
	bool found = false;
   int result = -1;
   int searchIndex = 0;
   
   // If the bag is empty, itemCount is zero, so loop is skipped
   while (!found && (searchIndex < itemCount))
   {
      if (items[searchIndex] == target)
      {
         found = true;
         result = searchIndex;
      } 
      else
      {
         searchIndex++;
      }  // end if
   }  // end while
   
   return result;
}  // end getIndexOf


/** private - helper function for bubbleSort
 * @brief swaps two items of ItemType
 * @param a ItemType variable - will hold b's value
 * @param b ItemType variable - will hold a's value
 * Output: None
 */
template<class ItemType>
void ArrayBag<ItemType>::swap(ItemType& a, ItemType& b)
{
   ItemType temp = a;
   a = b;
   b = temp;
}


/**
 * @brief Sorts items in ascending order using a bubble sort
 * Input: None
 * Output: None
 */
template<class ItemType>
void ArrayBag<ItemType>::bubbleSort()
{
   int length = itemCount; // length of array items[]

   // Outer loop for number of passes (length - 1 passes)
   for (int i = 0; i < length - 1; i++)
   {
      // Inner loop
      for (int j = 0; j < length - i - 1; j++)
      {
         // Compare adjacent elements, swap if necessary
         if (items[j] > items[j+1])
            swap(items[j], items[j+1]);
      } // end inner for loop

   } // end for
} // end bubbleSort


/**
 * @brief looks for an ItemType value (target) using a binarySearch
 * Iterative version
 * @param target ItemType variable
 * @return true if target found, false otherwise
 */
template<class ItemType>
bool ArrayBag<ItemType>::binarySearch(const ItemType target) const
{
   // Iterative binary search
   int left = 0;
   int right = itemCount - 1;

   while (left <= right)
   {
      // find midpoint
      int mid = left + (right - left) / 2;

      if (items[mid] == target)
         return true;
      
      if (items[mid] < target)
         left = mid + 1;
      else
         right = mid - 1;
   }  // end while

   return false;
}  // end binarySearch


/** private - helper function for binarySearchRecursive
 * @brief searches for an ItemType value (target) using a recursive binary search
 * @param target ItemType variable to search
 * @param first beginning of array
 * @param last end of array
 * @return true if found, false otherwise
 */
template<class ItemType>
bool ArrayBag<ItemType>::recursiveSearchHelper(const ItemType target, int first, int last) const
{
   if (first <= last)
   {
      // find midpoint
      int mid = first + (last - first) / 2;

      if (items[mid] == target)
         return true;

      if (items[mid] < target)
         return recursiveSearchHelper(target, mid + 1, last);
      else
         return recursiveSearchHelper(target, first, mid - 1);
   }
   return false;
}  // end recursiveSearchHelper


/**
 * @brief Calls recursiveSearchHelper (which performs the search)
 * @param target ItemType variable to look for
 * @return true if target was found, false otherwise
 */
template<class ItemType>
bool ArrayBag<ItemType>::binarySearchRecursive(const ItemType target) const
{
   return recursiveSearchHelper(target, 0, itemCount - 1);  
}  // end binarySearchRecursive