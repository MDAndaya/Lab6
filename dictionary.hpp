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
    Dictionary(const string &fileName);
    virtual ~Dictionary();

};

#endif //LAB6_DICTIONARY_HPP
