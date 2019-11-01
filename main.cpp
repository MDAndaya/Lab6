#include <iostream>
#include <fstream>
#include "dictionary.hpp"

using namespace std;

void showMenu() {
    cout << "1 - Print dictionary" << endl;
    cout << "2 - Find word definition" << endl;
    cout << "3 - Enter new word and definition" << endl;
    cout << "4 - Exit" << endl;
    cout << ">> ";
};

void searchWord(Dictionary& d) {
    cout << "Enter a word to define: " << endl;
    cout << ">> ";
    string input;
    if (cin >> input)
        d.findDef(input);
}

void addWord(Dictionary& d) {
    cout << "Enter a word to add: " << endl;
    cout << ">> ";
    string inputW, inputD;
    if (cin >> inputW) {
        cout << "Define " << inputW << ": " << endl;
        cout << ">> ";
        cin.ignore(256, '\n');
        if (getline(cin, inputD)) {
            d.addDef(inputW, inputD);
        }
    }
}

int main() {
    cout << "Creating Dictionary" << endl;
    ifstream file;
    file.open("dictionary.txt");;
    Dictionary d(file);

    while (true) {
        char input;
        showMenu();
        if (cin >> input) {
            switch(input) {
                case '1':
                    d.printAll();
                    cout << endl;
                    break;
                case '2':
                    searchWord(d);
                    break;
                case '3':
                    addWord(d);
                    break;
                case '4':
                    cout << "bye bye" << endl;
                    exit(0);
                default:
                    cout << "invalid input" << endl;
                    break;
            }
        }
    }
}