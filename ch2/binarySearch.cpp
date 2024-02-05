#include <iostream>
#include <string>

/**
 * @brief Searches the array anArray[first] through anArray[last]
 * for a given value by using a binary search.
 * @pre 0 <= first, last <= SIZE - 1, where SIZE is the maximum size of the array
 * and anArray[first] <= anArray[first + 1] <= ... <= anArray[last]
 * @post anArray is unchanged and either anArray[index] contains the given value
 * or index == -1
 * 
 * @param anArray 
 * @param first 
 * @param last 
 * @param target 
 * @return int 
 */
int binarySearch(const int anArray[], int first, int last, int target)
{
    int index = 0;
    if(first > last)
        index = -1; // target not in original array
    else
    {
        // If target is in anArray, anArray[first] <= target <= anArray[last]
        int mid = first + (last - first) / 2;
        
        if (target == anArray[mid])
            index = mid; // target found at anArray[mid]
        else if (target < anArray[mid])
            // Point X
            index = binarySearch(anArray, first, mid - 1, target);
        else
            // Point Y
            index = binarySearch(anArray, mid + 1, last, target);
    }   // end if
    return index;
}   // end binarySearch



int main()
{

    const int myArray[] = {1, 5, 9, 12, 15, 21, 29, 31};
    int length = sizeof(myArray) / sizeof(int);
    int target = 9;

    // Perform binary search
    std::cout << binarySearch(myArray, 0, length, target);
    std::cout << std::endl;
    return 0;
}