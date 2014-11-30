/* 
 * File:   Reader.cpp
 * Author: Sam Song
 * 
 * Created on November 17, 2014,
 */

#include "Reader.h"
#define	READER_H
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

Reader::Reader() {
}

void Reader::loadFile(string fileName) {
    if(vectorOfWords.size() > 0)    //checks the Reader for previous uses and erases the data from them.
        vectorOfWords.empty();  
    ifstream inputFile;
    
    inputFile.open(fileName.c_str()); // Open file
    if (!inputFile.good()) // Validate if file can be opened
    {
        cout << "The file could not be opened. Program is terminating." << endl;
        exit(1);
    }

    char buffer[1024]; // Buffer to hold a field of data

    string word;
    int lineNum = 0;

    // read in an entire line at a time and store into buffer
    while (inputFile.getline(buffer, 1024)) {

        lineNum++;
//                cout << buffer << endl;
//                cout << endl;

        istringstream iss(buffer); // store buffer into istringstream object

        int wordCount = 0;
        // use istringstream operator >> to get each word separated by a whitespace
        while (iss >> word) {
            wordCount++;
            // create a word with the line and word number as attributes
            Word w;
//            cout << word << endl;
            w.word = word;
            w.line = lineNum;
            w.column = wordCount;


            vectorOfWords.push_back(w); // add word to vectorOfWords


        } // end while


    } //end while


//    cout << "size" << vectorOfWords.size() << endl;
} // end loadFile

//Returns the vector of all the words 
vector<Word> getInput()
{
    return vectorOfWords;
}



//void Reader::displayInput() {
//
//    for (int index = 0; index < vectorOfWords.size(); index++) {
//        cout << "Word: " << vectorOfWords[index].word << endl;
//        cout << "Line: " << vectorOfWords[index].line << endl;
//        cout << "Column: " << vectorOfWords[index].column << endl;
//        cout << endl;
//    }
//}
