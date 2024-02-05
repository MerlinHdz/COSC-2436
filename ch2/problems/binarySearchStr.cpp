#include <iostream>
#include <string>

/**
 * @brief 
 * 
 * @param anArray 
 * @param first 
 * @param last 
 * @param target 
 * @return int 
 */
int binarySearchStr(std::string anArray[], int first, int last, std::string target)
{
    if (first > last)
    {
        return -1; // target not in original array
    }

    int mid = first + (last - first) / 2;

    if (anArray[mid] == target)
    {
        return mid; // target found at anArray[mid]
    }
    else if (anArray[mid] < target)
    {
        // Search right half of the array
        return binarySearchStr(anArray, mid+1, last, target);
    }
    else
    {
        // Search left half of the array
        return binarySearchStr(anArray, first, mid - 1, target);
    }
}   // end binarySearchStr


int main()
{
    std::string myArray[5] = {"Alpha", "Bravo", "Charlie", "Delta", "Foxtrot"};

    std::string target = "Charlie";
    int length = sizeof(myArray) / sizeof(std::string);
    
    std::cout << binarySearchStr(myArray, 0, length, target);
    std::cout << std::endl;
}