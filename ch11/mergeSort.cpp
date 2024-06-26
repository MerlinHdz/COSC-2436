

const int MAX_SIZE = 20;

/** Merges two sorted array segments theArray[first..mid] and
 theArray[mid+1..last] into one sorted array.
 @pre first <= mid <= last. The sub-arrays theArray[first..mid] and
 theArray[mid+1..last] are each sorted in increasing order.
 @post theArray[first..last] is sorted.
 @param theArray The given array.
 @param first The index of the beginning of the first segment in theArray.
 @param mid The index of the end of the first segment in theArray;
    mid + 1 marks the beginning of the second segment.
 @param last The index of the last element in the second segment in theArray.
 @note This function merges the two sub-arrays into a temporary 
 array and copies the result into the original array theArray.
*/
template <class ItemType>
void merge(ItemType theArray[], int first, int mid, int last)
{
    ItemType tempArray[MAX_SIZE]; // temporary array

    // Initialize the local indices to indicate the sub-arrays
    int first = first;  // Beginning of first sub-array
    int last1 = mid;    // End of first sub-array
    int first2 = mid+1; // Beginning of second sub-array
    int last2 = last;   // End of second sub-array

    // While both sub-arrays are not empty, copy the
    // smaller item into the temporary array
    int index = first1;
    while( (first1 <= last1) && (first2 <= last2) )
    {
        // At this point, tempArray[first..index-1] is in order
        if (theArray[first1] <= theArray[first2])
        {
            tempArray[index] = theArray[first1];
            first++;
        }
        else
        {
            tempArray[index] = theArray[first2];
            first2++
        }   // end if
        index++;
    }   // end while
    // Finish off the second sub-array, if necessary
    while (first2 <= last2)
    {
        // At this point, tempArray[first..index-1] is in order
        tempArray[index] = theArray[first2];
        first2++;
        index++;
    }   // end for

    // Copy the result back into the original array
    for (index = first; index <= last; index++)
        theArray[index] = tempArray[index];        
}   // end merge


/** Sorts the items in an array into ascending order.
 @pre theArray[first..last] is an array.
 @post theArray[first..last] is sorted in ascending order.
 @param theArray the given array.
 @param first The index of the first element to consider in theArray.
 @param last The index of the last element to consider in theArray.
*/
template<class ItemType>
void mergeSort(ItemType theArray[], int first, int last)
{
    if (first < last)
    {
        // Sort each half
        int mid = first + (last - first) / 2; // Index of midpoint

        // Sort left half theArray[first..mid]
        mergeSort(theArray, first, mid);

        // Sort right half theArray[mid+1...last]
        mergeSort(theArray, mid + 1, last);

        // Merge the two halves
        merge(theArray, first, mid, last);
    }   // end if
}   // end mergeSort


// The merge sort is O(n x log n)