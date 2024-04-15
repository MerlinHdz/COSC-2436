/** Sorts the items in an array into ascending order.
 * @pre None
 * @post theArray is sorted into ascending order; n is unchanged.
 * @param theArray The given array
 * @param n The size of theArray
*/

template<class ItemType>
void insertionSort(ItemType theArray[], int n)
{
    // unsorted = first index of the unsorted region
    // loc = index of insertion in the sorted region.
    // nextItem = next item in the unsorted region
    for (int unsorted = 1; unsorted < n; unsorted++)
    {
        ItemType nextItem = theArray[unsorted];
        int loc = unsorted;
        while ( (loc > 0) && (theArray[loc - 1] > nextItem))
        {
            // Shift theArray[loc - 1] to the right
            theArray[loc] = theArray[loc - 1];
            loc--;
        }   // end while
        // at this point, theArray[loc] is where nextItem belongs
        theArray[loc] = nextItem; // Insert nextItem into sorted region
        // end for
    }
}

// The insertion sort is O(n^2) in the worst case

// The insertion sort is O(n) in the best case

