//
// Created by MDand on 2019-10-30.
//

#include <fstream>
#include <iostream>
#include "dictionary.hpp"

Dictionary::Dictionary(ifstream& file) {
    string word, definition;
    while (file) {
        string line;
        // Get first line: the word
        getline(file, line, '\n');
        word = line;

        // Get second line: the definition
        getline(file, line, '\n');
        definition = line;

        // Add this word and definition if the scans aren't empty
        if (word != "" && definition != "")
            definitions.insert(make_pair(word, definition));
    }

    file.close();
}

void Dictionary::printAll() {
    for (auto it = definitions.begin(); it != definitions.end(); ++it) {
        cout << it->first << " - " << it->second << endl;
    }
}

void Dictionary::findDef(string word) {
    for (auto it = definitions.begin(); it != definitions.end(); ++it) {
        if (it->first == word) {
            cout << it->first << " - " << it->second << endl;
            return;
        }
    }
    cout << "Word not found in dictionary" << endl;
}

void Dictionary::addDef(string word, string def) {
    ofstream ofile;
    ofile.open("dictionary.txt",  ios::app);
    ofile << word << "\n" << def << endl;
    ofile.close();
    definitions.insert(make_pair(word, def));
}

Dictionary::~Dictionary() {}