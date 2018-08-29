#include <iostream>

#include "radix-tree/tree.h"
#include "parse/Parse.h"

using namespace std;


int main(int argc, char *argv[]) {
    // map <string, int> words;

    // words["HOLA"] = 1;
    // auto it = words.find("HOLA");
    // if (it != words.end()) {
    //     cout << it->second << endl;
    // } else {
    //     cout << "NOT" << endl;
    // }
    Parse *parse = new Parse("../../files/");
    parse->processFile();
    // Tree t;

    // for(multimap<string, Word *>::iterator it = parse->words.begin(), end = parse->words.end(); it != end; it = parse->words.upper_bound(it->first)) {
    //     t.add(it->first);
    // }


    // for(int i = 0; i < list.size(); i++)
    // {

    //     int start = list.at(i).start;
    //     int end = list.at(i).end;
    //     file.seekg(start);
    //     std::string s;
    //     s.resize(end - start);
    //     file.read(&s[0], end - start);
    //     cout << "IdFile: " << list.at(i).idFile << " Content: " << list.at(i).content;
    //     cout << " Pos: " << list.at(i).start << " - "  << list.at(i).end << endl;
    //     cout << "s: " << "|" << s << "|" << endl;
    // }
    // vector<string> g1;
    // // g1.push_back("../../files/spanishText_10000_15000");
    // g1.push_back("../../files/test");



    // for (auto it = words.begin(); it != words.end(); ++it) {
    //     t.add(*it);
    // }

    while (true) {
        string word;
        cout << "Please enter a word ..." << endl;
        cin >> word;
        if (word == "exit") {
            break;
        }
    //     string result;
    //     bool found = t.find(word, result);
    //     if (found) {
    //         cout << ":) Found " << result << endl;
    //         parse->someContent(result);
    //     } else {
    //         cout << ":( NOT Found";
    //     }
    //     cout << endl;
    }
    return 0;
}
