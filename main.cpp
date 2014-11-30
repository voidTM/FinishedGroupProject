/* 
 * File:   main.cpp
 * Author: kim
 *
 * Created on November 15, 2014, 7:49 PM
 */

#include <cstdlib>
#include "HashClass.h"
#include "Reader.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void addData(HashClass hc);
void removeData(HashClass hc);
void findAndDisplayData(HashClass hc);
void listHashTableSequence(HashClass hc);
void listSortedData(HashClass hc);
void printIndentedTree(HashClass hc);
void printEfficiency(HashClass hc);
void spellCheck(HashClass hc, HashClass hc2);
void writeToFile(HashClass hc);

int main() {
    // Load dictionary file into hash table
    HashClass hashDictionary;
    hashDictionary.loadFile("dict.txt");
    hashDictionary.loadToHash();

    // Load input file into hash table
    HashClass hashInput;
    hashInput.loadFile("inputErrors.txt");
    hashInput.loadToHash();

    enum MenuChoice {
        MENU_ADD_NEW_DATA = 1,
        MENU_REMOVE_DATA = 2,
        MENU_FIND_AND_DISPLAY_DATA = 3,
        MENU_LIST_IN_HASH_TABLE_SEQUENCE = 4,
        MENU_LIST_SORTED_DATA = 5,
        MENU_PRINT_INDENTED_TREE = 6,
        MENU_PRINT_EFFICIENCY = 7,
        MENU_SPELLCHECK = 8,
        MENU_WRITE_TO_FILE = 9,
        MENU_EXIT = 10
    };

    const string strOperationSuccess = "\nFinished task, Repeating menu:\n";
    const string strMenuDisplay = "What operation would you like to perform?: \n\n"
            "1. Add new data to input file\n"
            "2. Remove data from input file\n"
            "3. Find and display one data from the input file using the primary key\n"
            "4. List data in the dictionary hash table\n"
            "5. List data in the input file in key sequence (sorted)\n"
            "6. Print data in the input file as an indented binary tree\n"
            "7. Print efficiency of the dictionary hash table\n"
            "8. Spell check input file\n"
            "9. Write the dictionary file back to a file in hash table sequence\n"
            "10. Exit\n";


    int menuOption;
    cout << strMenuDisplay << endl;

    do {
        cin >> menuOption; // get menu choice
        cout << endl;

        // check for valid menu choice then call it
        switch (menuOption) {
            case MENU_ADD_NEW_DATA:
                cin.clear();
                cin.ignore();
                addData(hashInput);
                cout << strOperationSuccess << endl;
                cout << "\n\n\n\n\n";
                cout << strMenuDisplay << endl;
                break;
            case MENU_REMOVE_DATA:
                cin.clear();
                cin.ignore();
                removeData(hashInput);
                cout << strOperationSuccess << endl;
                cout << "\n\n\n\n\n";
                cout << strMenuDisplay << endl;
                break;
            case MENU_FIND_AND_DISPLAY_DATA:
                cin.clear();
                cin.ignore();
                findAndDisplayData(hashInput);
                cout << strOperationSuccess << endl;
                cout << "\n\n\n\n\n";
                cout << strMenuDisplay << endl;
                break;
            case MENU_LIST_IN_HASH_TABLE_SEQUENCE:
                cin.clear();
                cin.ignore();
                listHashTableSequence(hashDictionary);
                cout << strOperationSuccess << endl;
                cout << "\n\n\n\n\n";
                cout << strMenuDisplay << endl;
                break;
            case MENU_LIST_SORTED_DATA:
                cin.clear();
                cin.ignore();
                listSortedData(hashInput);
                cout << strOperationSuccess << endl;
                cout << "\n\n\n\n\n";
                cout << strMenuDisplay << endl;
                break;
            case MENU_PRINT_INDENTED_TREE:
                cin.clear();
                cin.ignore();
                printIndentedTree(hashInput);
                cout << strOperationSuccess << endl;
                cout << "\n\n\n\n\n";
                cout << strMenuDisplay << endl;
                break;
            case MENU_PRINT_EFFICIENCY:
                cin.clear();
                cin.ignore();
                printEfficiency(hashDictionary);
                cout << strOperationSuccess << endl;
                cout << "\n\n\n\n\n";
                cout << strMenuDisplay << endl;
                break;
            case MENU_SPELLCHECK:
                cin.clear();
                cin.ignore();
                spellCheck(hashDictionary, hashInput);
                cout << strOperationSuccess << endl;
                cout << "\n\n\n\n\n";
                cout << strMenuDisplay << endl;
                break;
            case MENU_WRITE_TO_FILE:
                cin.clear();
                cin.ignore();
                writeToFile(hashDictionary);
                cout << strOperationSuccess << endl;
                cout << "\n\n\n\n\n";
                cout << strMenuDisplay << endl;
                break;
            case MENU_EXIT:
                cin.clear();
                cin.ignore();
                cout << "You have exited the program." << endl;
                exit(0);
                break;
            default:
                cin.clear();
                cin.ignore();
                cout << menuOption << " is not a valid menu choice. Enter again.\n" << endl;
                cout << strMenuDisplay << endl;
                break;
        }


    } while (true);




    return 0;
}

// Functions

void addData(HashClass hc) {
    cout << "Enter the word you would like to add to the input file:" << endl;
    string inputWord;
    getline(cin, inputWord);
    cout << endl;
    cout << endl;

    hc.addToHash(inputWord);
    cout << "You have added the word " << inputWord << " to the input file." << endl;

};

void removeData(HashClass hc) {
    cout << "Enter the word you would like to remove from the input file:" << endl;
    string inputWord;
    getline(cin, inputWord);
    hc.removeItem(inputWord);

};

void findAndDisplayData(HashClass hc) {
    cout << "Enter the word you would like to display: " << endl;
    string inputWord;
    getline(cin, inputWord);


    hc.printWord(inputWord);


};

void listHashTableSequence(HashClass hc) {
    int choice;
    int bucketNumber;
    hc.printTable();

    do {
        cout << "Enter the bucket you would like to display: " << endl;
        cin >> bucketNumber;
        hc.printItemsInIndex(bucketNumber);

        cout << "Would you like to continue? Enter 1 for yes and 0 for no:" << endl;
        cin >> choice;

    } while (choice);

};

void listSortedData(HashClass hc) {

//    hc.createHashTableVector();
    
    hc.createWordVector();
    hc.createBST();

};

void printIndentedTree(HashClass hc) {
//    hc.createHashTableVector();
    hc.createWordVector();
    hc.createIndentedBST();
};

void printEfficiency(HashClass hc) {
    hc.printLoadFactor();
    hc.avgNodesInLists();
    hc.printLongestLinkedList();
};

void spellCheck(HashClass dictionary, HashClass input) {
        input.createWordVector(); // Create a vector of all the words in the
                                    // input file from the hash table
                                    // so it includes new data added
        
        
        // Demonstrate spell checking
        // Check the input vector of words against the dictionary hash table
        dictionary.spellCheck(input.getWords());


};

void writeToFile(HashClass hc) {
    hc.writeToFile();
    cout << "Contents of the dictionary hash table has been written to an output file." << endl;
};