/* 
 * File:   HashClass.cpp
 * Author: kim
 * 
 * Created on November 15, 2014, 7:50 PM
 */

#include "HashClass.h"
#include "BST.h"

// constructor
// make empty hash table

HashClass::HashClass() {
    for (int index = 0; index < tableSize; index++) {
        HashTable[index] = new Node;
        HashTable[index]->word = "empty";
        HashTable[index]->line = 0;
        HashTable[index]->column = 0;
        HashTable[index]->next = NULL;

    }


    tableItems = 0; // initialize tableItems, keep track of how many items are added 

}


// loads dictionary words read in file in to the hash table
// duplicated words will have their frequencies incremented

void HashClass::loadToHash() {
    for (int index = 0; index < vectorOfWords.size(); index++) {
        if (findWord(vectorOfWords[index].word)) // if the word is found, update the frequency
        {
            addFrequency(vectorOfWords[index].word); // add to frequency of word
        } else // if the word isn't loaded into hash table yet, add new word
        {
            add(vectorOfWords[index].word, vectorOfWords[index].line, vectorOfWords[index].column);
            tableItems++;
        }
    } // end for
}

// takes in input word from user to add to hash table
// duplicated words will have their frequencies incremented

void HashClass::addToHash(string word) {

    if (findWord(word)) // if the word is found, update the frequency
    {
        addFrequency(word); // add to frequency of word
    } else // if the word isn't loaded into hash table yet, add new word
    {
        add(word, 0, 0);
        tableItems++;
    }

}


// the key will be the word
// calculate index from key

int HashClass::HashFunction(string key) {
    int hash = 0;
    int index;

    for (int index = 0; index < key.length(); index++) {
        hash = hash + (int) key[index]; // adds the ascii values of each letter
        // in the string

    };

    index = hash % tableSize;

    return index;
}


// add a new word

void HashClass::add(string word, int line, int column) {
    int index;
    index = HashFunction(word);

    // if bucket is empty
    if (HashTable[index]->word == "empty") {
        HashTable[index]->word = word;
        HashTable[index]->line = line;
        HashTable[index]->column = column;
        HashTable[index]->frequency = 1;
    }// end if
    else // if bucket is not empty
    {
        Node* nodePtr = HashTable[index]; // node pointing to head
        Node* newNode = new Node;
        Node* prev = NULL;

        newNode->word = word;
        newNode->line = line;
        newNode->column = column;
        newNode->frequency = 1;
        newNode->next = NULL;

        while (nodePtr != NULL) {
            prev = nodePtr;
            nodePtr = nodePtr->next;
        } // end while
        prev->next = newNode;

    } // end else



}

// returns true if word is found, false if word is not found

bool HashClass::findWord(string word) {
    int index;
	int tries = 0;
    index = HashFunction(word);
    bool nameFound = false;
    int line;
    int column;
    int frequency;
	cout << "Index is: " << index << endl;
    Node* nodePtr;
    nodePtr = HashTable[index];
	cout << "word at index is " << nodePtr->word << endl;
    while (nodePtr != NULL) {
        if (nodePtr->word == word)
		{
            nameFound = true;
            line = nodePtr->line;
            column = nodePtr->column;
            frequency = nodePtr->frequency;
		}
        nodePtr = nodePtr->next;
		tries++;
    }

	cout << "It took " << tries << " until word was found" << endl;
    return nameFound; // if found, return true

}

// finds a word in the hash table and prints its information

void HashClass::printWord(string word) {
    int index;
    index = HashFunction(word);
    bool nameFound = false;
    int line;
    int column;
    int frequency;

    Node* nodePtr;
    nodePtr = HashTable[index];
    while (nodePtr != NULL) {
        if (nodePtr->word == word) {
            nameFound = true;
            line = nodePtr->line;
            column = nodePtr->column;
            frequency = nodePtr->frequency;
        }
        nodePtr = nodePtr->next;
    }

    if (nameFound) {
        cout << "The word <" << word << "> was found." << endl;
        cout << "Line #: " << line << endl;
        cout << "Column # " << column << endl;
        cout << "Frequency: " << frequency << endl;
    } else {
        cout << "The word <" << word << "> cannot be found in hash table." << endl;
    }


}

// if a word is already in the hash table, the frequency is incremented

void HashClass::addFrequency(string word) {
    // search for word and modify frequency
    int index;
    index = HashFunction(word);

    Node* nodePtr;
    nodePtr = HashTable[index];
    while (nodePtr != NULL) {
        if (nodePtr->word == word) {
            cout << "adding fre?" << endl;
            nodePtr->frequency++;

        }
        nodePtr = nodePtr->next;
    }// end while

}


// returns number of nodes in a bucket

int HashClass::numberOfItemsInIndex(int index) {

    int count = 0;

    if (HashTable[index]->word == "empty") {
        return count;
    } else {
        count++;

        Node* nodePtr = HashTable[index]; // node pointing to head
        while (nodePtr->next != NULL) // traverse through bucket
        {
            count++;
            nodePtr = nodePtr->next;

        }

    } // end else
    return count;
}

// prints only the first items of each bucket

void HashClass::printTable() {
    int numItemsInBucket;

    for (int index = 0; index < tableSize; index++) {
        numItemsInBucket = numberOfItemsInIndex(index);

        cout << "Word: " << HashTable[index]->word << endl;
        cout << "Line #: " << HashTable[index]->line << endl;
        cout << "Column #: " << HashTable[index]->column << endl;
        cout << "Frequency of word: " << HashTable[index]->frequency << endl;
        cout << "Number of nodes in bucket: " << numItemsInBucket << endl;
        cout << endl;

    } // end for

}

// prints the entire bucket chosen

void HashClass::printItemsInIndex(int index) {

    Node* nodePtr = HashTable[index];

    cout << "The following nodes are in this index/bucket: " << endl;
    while (nodePtr != NULL) {
        cout << "Word: " << nodePtr->word << endl;
        cout << "Line #1: " << nodePtr->line << endl;
        cout << "Column #1: " << nodePtr->column << endl;
        cout << "Frequency of word: " << nodePtr->frequency << endl;
        cout << endl;

        nodePtr = nodePtr->next;

    }

}

// removes an item from the hash table

void HashClass::removeItem(string word) {
    int index;
    index = HashFunction(word);

    // Case 1: Bucket is empty
    if (HashTable[index]->word == "empty") {
        cout << word << " not found in hash table" << endl;
    }// Case 2: Match is in the first item and it is the only item in the bucket
    else if (HashTable[index]->word == word && HashTable[index]->next == NULL) {
        HashTable[index]->word = "empty"; // erase items
        HashTable[index]->line = 0;
        HashTable[index]->column = 0;
    }// Case 3: Match is in first item but more than one item is in the bucket
    else if (HashTable[index]->word == word) {
        Node* delPtr;
        delPtr = HashTable[index]; // set to first item in item in the bucket
        HashTable[index] = HashTable[index]->next; // second item in list is now the first item
        delete delPtr; // delPtr still pointing to first item in bucket, delete it

    }// Case 4: Bucket contains more than one item and bucket may or may not contain match
    else {
        Node* nodePtr;
        nodePtr = HashTable[index]->next;
        Node* prev;
        prev = HashTable[index];

        while (nodePtr != NULL && nodePtr->word != word) {
            prev = nodePtr;
            nodePtr = prev->next;
        }

        if (nodePtr == NULL) {
            cout << word << " was not found in hash table" << endl;
        } else {
            Node* delPtr = nodePtr;
            nodePtr = nodePtr->next;
            prev->next = nodePtr;
            delete delPtr;

        }

    }

}

// print the index and the number of items of the linked list that is the longest

void HashClass::printLongestLinkedList() {
    int indexOfLongest;
    int itemsCount = 0;


    for (int index = 0; index < tableSize; index++) {
        if (numberOfItemsInIndex(index) > itemsCount)
            itemsCount = numberOfItemsInIndex(index);
        indexOfLongest = index;
    };

    cout << "The index/bucket with the longest linked list is " << indexOfLongest <<
            " and the number of items inside it is " << itemsCount << endl;

};

// calculates and prints the average number of nodes in the linked lists

void HashClass::avgNodesInLists() {
    int total = 0;

    for (int index = 0; index < tableSize; index++) {
        total += numberOfItemsInIndex(index); // Count up all nodes
    };

    cout << "The average number of nodes in the linked lists is " <<
            total / tableSize << endl;

}

// writes the contents of the hash table back into a file, in hash table sequence

void HashClass::writeToFile() {
    ofstream outputFile;

    outputFile.open("hashtable_file_output.txt"); // Open file
    if (!outputFile.is_open()) // Validate if file can be opened
    {
        cout << "The file could not be opened. Program is terminating." << endl;
    }


    // Write hash table ordered words to file
    // Nested loop, go through one bucket and all its items at a time
    for (int index = 0; index < tableSize; index++) {
        Node* nodePtr = HashTable[index]; // node pointing to head
        while (nodePtr->next != NULL) // traverse through bucket
        {
            outputFile << nodePtr->word << endl;
            nodePtr = nodePtr->next;

        }; //end while
    }; //end for

    outputFile.close(); // Close file
}


// traverse through entire hash table and create an object containing a word
// and its frequency for each item
// will be used for binary search tree later

void HashClass::createWordVector() {

    for (int index = 0; index < tableSize; index++) {
        Node* nodePtr = HashTable[index]; // node pointing to head

        // traverse through bucket
        for (Node* nodePtr = HashTable[index]; nodePtr != NULL; nodePtr = nodePtr->next) {
            if (nodePtr->word != "empty") {
                wordStruct listOfWords;
                listOfWords.word = nodePtr->word;
                listOfWords.frequency = nodePtr->frequency;
                Words.push_back(listOfWords);
            }; //end for

        };
    }; // end for
}

void HashClass::createBST() {

    BST byfrequencyBST;
    // read in data from vector to BST, sorting into tree by frequency field
    for (int index = 0; index < Words.size(); index++) {
        byfrequencyBST.searchTreeInsert(Words[index].frequency, Words[index].word);
    };

    byfrequencyBST.inorderTraverse();

}

void HashClass::createIndentedBST() {

    // create BST
    BST byfrequencyBST;
    // read in data from vector to BST, sorting into tree by frequency field
    for (int index = 0; index < Words.size(); index++) {
        byfrequencyBST.searchTreeInsert(Words[index].frequency, Words[index].word);
    };

    byfrequencyBST.inorderTraversewithHeight();

}

void HashClass::spellCheck(vector<wordStruct>& Words) {

    for (int index = 0; index < Words.size(); index++) {
        if (findWord(Words[index].word))
            cout << "The word " << Words[index].word << " is spelled correctly." << endl;
        else
            cout << "The word " << Words[index].word << " is spelled incorrectly." << endl;
    };

};

