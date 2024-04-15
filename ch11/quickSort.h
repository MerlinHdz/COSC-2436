/** Sorts an array into ascending order. Users the quick sort with
 median-of-three pivot selection for array sof at least MIN_SIZE
 entries, and uses the insertion sort for other arrays.
 @pre theArray[first..last] is an array.
 @post theArray[first..last] is sorted.
 @param theArray The given array.
 @param first The index of the first element to consider in theArray.
 @param last The index of the last element to consider in theArray.
*/
template <class ItemType>
void quickSort(ItemType theArray[], int first, int last)
{
    if ( (last - first + 1) < MIN_SIZE)
    {
        insertionSort(theArray, first, last);
    }
    else
    {
        // Create the partition: S1 | Pivot | S2
        int pivotIndex = partition(theArray, first, last);

        // Sort sub-arrays S1 and S2
        quickSort(theArray, first, pivotIndex - 1);
        quickSort(theArray, pivotIndex + 1, last);
    }   // end if
}


// Worst case: O(n^2)

// Average case: O(n log n)