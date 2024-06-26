#include <iostream>
#include <string>

/**
 * @brief Writes characters in an array backward.
 * @pre The array anArray contains size characters, where size >= 0.
 * @post None.
 * @param anArray The array to write backward
 * @param first The index of the first character in the array
 * @param last The index of the last character in the array
 */
void writeArrayBackward(const char anArray[], int first, int last)
{
    if (first <= last)
    {
        // Write the last character
        std::cout << anArray[last] << " ";

        // Write the rest of the array backward
        writeArrayBackward(anArray, first, last - 1);
    }   // end if
    // first > last is the base case - do nothing
}   // end writeBackward


int main()
{
    const char myArray[] = {'A', 'B', 'C', 'D'};
    writeArrayBackward(myArray, 0, 3);
    std::cout << "\n";
}