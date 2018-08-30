#include <iostream>

#include "radix-tree/tree.h"
#include "parse/Parse.h"

using namespace std;


int main(int argc, char *argv[]) {
    // unordered_multimap <string, int> words;
    // words.insert(make_pair("hola", 1));
    // words.insert(make_pair("hola", 2));

    // // auto it = words.equal_range("hola");
    // // it.first;
    // // cout << << endl;

    // for (auto it = words.begin(); it != words.end(); it++) {

    // }

    // for (auto it = words.begin(); it != words.end(); it = words.equal_range(it->first).first) {
    //     cout << it->first << endl;
    // }

    // auto it = words.upper_bound("hola");

    // cout << (--it)->second << endl;



    // words["HOLA"] = 1;
    // auto it = words.find("HOLA");
    // if (it != words.end()) {
    //     cout << it->second << endl;
    // } else {
    //     cout << "NOT" << endl;
    // }
    Parse *parse = new Parse("../../files/");
    parse->processFile();

    // for(unordered_multimap<string, WordDoc *>::iterator it = parse->words.begin(), end = parse->words.end(); it != end; it = parse->words.upper_bound(it->first)) {
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

    // parse->find("JOSUE JOEL");

    while (true) {
        string word;
        cout << "Please enter a word ..." << endl;
        getline(cin, word);
        if (word == "exit") {
            break;
        }
        string result;

        parse->find(word);
        // if (found) {
        //     cout << ":) Found " << result << endl;
        //     // parse->someContent(result);
        // } else {
        //     cout << ":( NOT Found";
        // }
        // cout << endl;
    }
    return 0;
}
