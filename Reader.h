/* 
 * File:   Reader.h
 * Author: Sam Song
 *
 * Created on November 17, 2014,
 */

/**********************************************************************
 * This module reads in an input file of words, some of which are
 * misspelled. It parses the file into words, and uses the information
 * of each word (the word itself, its line number, column number) to create
 * a word object. The word objects are all stored in a vector called
 * vectorOfWords. This word vector is used to make the hash table.
 ************************************************************************/



#ifndef READER_H
#define	READER_H
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Word 
{
    string word;
    int line;
    int column;
};

class Reader {
protected:
    vector<Word> vectorOfWords;


public:
    Reader();

    void loadFile(string fileName);
    void clear();
   
    friend class HashClass;
};

#endif	/* READER_H */

