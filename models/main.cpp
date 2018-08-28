#include <iostream>

#include "radix-tree/tree.h"
#include "parse/Parse.h"

using namespace std;


int main(int argc, char *argv[]) {
    vector<string> g1;
    // g1.push_back("../../files/spanishText_10000_15000");
    g1.push_back("../../files/test");

    Tree t;

    vector <string> words;

    vector<string> result;
    for (auto ir = g1.crbegin(); ir != g1.crend(); ++ir)
    {
        cout << *ir << endl;
        Parse *parse = new Parse(*ir);
        result = parse->processFile();
        cout << endl;
    }

    for (auto it = result.begin(); it != result.end(); ++it) {
        t.add(*it);
    }

    while (true) {
        string word;
        cout << "Please enter a word ..." << endl;
        cin >> word;
        if (word == "exit") {
            break;
        }
        if (t.find(word)) {
            cout << ":) Found " << word;
        } else {
            cout << ":( NOT Found";
        }
        cout << endl;
    }
    return 0;
}
