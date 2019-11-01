//
// Created by MDand on 2019-10-30.
//

#ifndef LAB6_DICTIONARY_HPP
#define LAB6_DICTIONARY_HPP

#include <map>
using namespace std;

class Dictionary {
private:
    map<string, string> definitions;
public:
    Dictionary(ifstream& file);
    virtual ~Dictionary();
    void printAll();
    void findDef(string word);
    void addDef(string word, string def);
};

#endif //LAB6_DICTIONARY_HPP
