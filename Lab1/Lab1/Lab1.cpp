// lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Lab1Header.h"

using namespace std;

int parsing(vector<string>& ​fileStrings, char* fileName) {
    ifstream ifs;
    ifs.open(fileName);
    if (!ifs.is_open()) {
        cout << "No such file" << endl;
        return int(result::fileNonexisted);
    }
    string word;
    while (ifs >> word) {
        ​fileStrings.push_back(word);
    }
    return int(result::success);
}

int usage(string& programName) {
    int requiredArguments = int(arrayIndices::expectedArgumentNumber) - 1;
    cout << programName << " requires " << requiredArguments
        << " argument:​" << endl;
    cout << "Example: <program_name> <input_file_name>" << endl;
    return int(result::wrongArgumentNumber);
}

int main(int argc, char* argv[])
{
    string programName = argv[int(arrayIndices::programName)];
    char* inputFileName = argv[int(arrayIndices::inputFileName)];
    int expectedArgumentNumber = int(arrayIndices::expectedArgumentNumber);

    if (argc != expectedArgumentNumber) {
        return usage(programName);
    }

    vector<string> ​fileStrings;
    if (parsing(​fileStrings, inputFileName) == int(result::fileNonexisted)) {
        return int(result::fileNonexisted);
    }

    vector<int> numericStrings;
    cout << "non-numeric strings:" << endl;
    for (size_t i = 0; i < ​fileStrings.size(); ++i ) {
        string word = ​fileStrings[i];
        bool isNumeric = true;
        for (char c : word) {
            if (!isdigit(c)) {
                isNumeric = false;
                break;
            }
        }
        if (isNumeric) {
            istringstream iss(word);
            int number;
            iss >> number;
            numericStrings.push_back(number);
        }
        else {
            cout << word << endl;
        }
    }

    cout << "-------------" << endl;
    cout << "numbers:" << endl;
    for (size_t i = 0; i < numericStrings.size(); ++i) {
        cout << numericStrings[i] << endl;
    }

    return int(result::success);


}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
