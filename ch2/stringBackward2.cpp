#include <iostream>
#include <string>

void writeBackward2(std::string word)
{
    int length = word.size(); // Length of string
    if (length > 0)
    {
        writeBackward2(word.substr(1, length - 1));

        // write the first character of word
        std::cout << word[0];

    }
    // else do nothing
}

int main()
{
    std::string myStr;
    std::cout << "Enter a string: ";
    std::cin >> myStr;

    // Print myStr in reverse
    writeBackward2(myStr);
    std::cout << std::endl;

}