//
// Created by MDand on 2019-10-30.
//

#include <fstream>
#include <sstream>
#include <iostream>
#include "dictionary.hpp"

Dictionary::Dictionary(const string& fileName) {
    cout << "fileName: " << fileName << endl;
    string word, defBuffer, definition;
    ifstream myFile;
    myFile.open(fileName);
    while (myFile) {
        string line;
        // Get first line: the word
        getline(myFile, line, '\n');
        word = line;

        //Get second line: the definition
        getline(myFile, line, '\n');
        definition = line;

        if (word != "" && definition != "")
            definitions.insert(make_pair(word, definition));
    }
    for (auto it = definitions.cbegin(); it != definitions.cend(); ++it) {
        cout << "word: " << it->first << endl;
        cout <<"definition: " << it->second << endl;
    }
    myFile.close();
}

Dictionary::~Dictionary() {}