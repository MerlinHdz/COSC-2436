/**
 * @file client.cpp
 * @brief 
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "LinkedList.h"
using namespace std;

int main()
{
    // Ask the user for a filename
    string filename;
    cout << "Enter the name of the file: ";
    cin >> filename;

    ifstream inputFile(filename);

    // Check if file was opened successfully
    if (!inputFile.is_open())
    {
        cout << "Error: Unable to open file." << endl;
        return 1;
    }
    else
    {
        // Create a LinkedList object
        LinkedList myList;

        string category;
        string line;

        // Add nodes to the LinkedList from the file's contents, until end of file is reached
        while (getline(inputFile, category) && getline(inputFile, line))
        {
            myList.addNode(category, line);
        }
    
        // Display the contents of the LinkedList
        cout << "Contents of the LinkedList:" << endl;
        vector<string> listContents = myList.toVector();

        string lastCategory = "";
        bool firstEntry = true; // Flag to know if this is the first entry
        
        for (int i = 0; i < listContents.size(); i+=2)
        {
            string category = listContents[i];
            string line = listContents[i+1];

    
            if (firstEntry || category != lastCategory)
            {
                cout << category << endl;
                cout << "    " << line << endl;

                lastCategory = category;
                firstEntry = false;
            }
            else
            {
                // the category is the same as last time
                cout << "    " << line << endl;
            }
        }
    }

    return 0;
}
