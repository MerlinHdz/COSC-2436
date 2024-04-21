#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "LinkedList.h"
using namespace std;

int main()
{
    string filename;
    cout << "Enter the name of the file: ";
    cin >> filename;

    ifstream inputFile(filename);

    if (!inputFile.is_open())
    {
        cout << "Error: Unable to open file." << endl;
        return 1;
    }
    else
    {
        LinkedList myList;

        string category;
        string line;

        while (getline(inputFile, category) && getline(inputFile, line))
        {
            myList.addNode(category, line);
        }

        
        // Test display of LinkedList contents
        cout << myList.getNumItems() << endl;
        

        cout << "Contents of the LinkedList:" << endl;
        vector<string> listContents = myList.toVector();

        for (int i = 0; i < listContents.size(); i++)
        {
            cout << listContents[i] << endl;
        }
    }

    return 0;
}
