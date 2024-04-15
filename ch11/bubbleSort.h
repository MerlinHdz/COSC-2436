#include <iostream>

/**
 * @brief Sorts the items in an array into ascending order.
 * @pre None
 * @post The array is sorted into ascending order; n is unchanged
 * @param theArray the given array
 * @param n The size of theArray
 */
template <class ItemType>
void bubbleSort(ItemType theArray[], int n)
{
    bool sorted = false;
    int pass = 1;

    while (!sorted && (pass < n))
    {
        // At this point, theArray[n+1-pass..n-1] is sorted
        // and all of its entries are > the entries in theArray[0..n-pass]
        sorted = true;
        for (int index = 0; index < n - pass; index++)
        {
            // At this point, all entries in theArray[0..index-1]
            // are <= theArray[index]
            int nextIndex = index + 1;
            if (theArray[index] > theArray[nextIndex])
            {
                // exchange entries - do a swap
                std::swap(theArray[index], theArray[nextIndex]);
                sorted = false; // signal change // not my favorite approach
            }
        }
        pass++;
    }   // end while
}