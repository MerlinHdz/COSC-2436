#include "bubbleSort.h"

int main()
{
    int numArray[] = {25, 30, 20, 80, 40, 60};
    int size = sizeof(numArray) / sizeof(numArray[0]);

    // display original array
    for (int i = 0; i < size; i++)
    {
        std::cout << numArray[i] << " ";
    }
    std::cout << std::endl;

    // Sort using bubbleSort
    bubbleSort(numArray, size);


    // display array again
    for (int i = 0; i < size; i++)
    {
        std::cout << numArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}