/* 
 * File:   HashClass.h
 * Author: kim
 *
 * Created on November 15, 2014, 7:50 PM
 */

#ifndef HASHCLASS_H
#define	HASHCLASS_H
#include <iostream>
#include <string>
#include "Reader.h"
#include <fstream>
#include <vector>
#include <map>
#include "math.h"
#include "BST.h"
using namespace std;

class HashClass:public Reader {
    private:
        int tableSize = 1000; // Since we are not doing rehashing,
                                           // we are making the number of buckets
                                           // very big
       
        // Each node in the hash table
        struct Node {
            Node* next; 
            string word;
            int line; 
            int column;
            int frequency;
        };
        // Hash table is an array of Node pointers with tableSize buckets
        Node** HashTable; 
        
        
        // Used to make a vector out of the hash table elements for the binary
        // search tree and to demonstrate spell checking
        struct wordStruct {
            string word;
            int frequency;
        };
        // vector of WordStructs
        vector<wordStruct> Words;
        
        
//		map<char, int> keyL;		scrapped
        // keep track of how many items are added 
        int tableItems; 
 
        
public:
    
    HashClass(); // Constructor builds empty hash table
    int HashFunction(string key); // Hash function that calculates the index from key
    void loadToHash(); // Takes the vector of words created from file and inserts each
                          // word into the hash table
    bool findWord(string word); // Returns true if word found, returns false if not
    void addFrequency(string word); // Function to increment frequency of item
    void add(string word, int line, int column); // Add an item to the hash table
    void addToHash(string word); // Takes word input by user and adds to hash table
    void removeItem(string word); // Find and removes data using key
    
    int numberOfItemsInIndex(int index); // Returns the number of items in one bucket
    
    void printWord(string word); // Find and display one data record using the primary key 
    void printTable(); // There is an option to print each first item of the buckets
    void printItemsInIndex(int index); // and then to print the entire list of each bucket,
                                       // because we don't want to print the entire 
                                       // dictionary Hash table.
   
    
  
    // Print the number of table items
    void printTableItems(){
        cout << "Number of table items: " << tableItems << endl;
               
    };
    
    
    // Print efficiency functions
    void printLoadFactor(){
        
        cout << "The load factor is " << tableItems/tableSize << "." << endl;
    };
    void printLongestLinkedList();
    void avgNodesInLists(); // Average number of nodes in linked lists
    
    
    void writeToFile(); // Write out data to file in hash table order
    
    
    void createWordVector(); // Creates a vector of words from hash table
    void createBST(); // Creates Binary Search Tree using vector of words from
                      // hash table
    void createIndentedBST(); // Creates BST for indented print
    
    // Spell checker function
    // Use a vector of words created for input file to check
    // input words against dictionary hash table
    void spellCheck(vector<wordStruct>& Words);
    
    // Returns vector of words
    vector<wordStruct>& getWords(){ 
        return Words; 
    };
    
    
    
    
    friend class BST;
    
};

#endif	/* HASHCLASS_H */

