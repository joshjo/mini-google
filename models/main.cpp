#include <iostream>

#include "radix-tree/tree.h"
#include "parse/Parse.h"

using namespace std;


int main(int argc, char *argv[]) {
    Parse *parse = new Parse("../../test/");
    vector<Word> list = parse->processFile();

    std::ifstream file("../../test/test");
    if(file.is_open())

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

    // Tree t;

    // vector <string> words;

    // vector<string> result;
    // for (auto ir = g1.crbegin(); ir != g1.crend(); ++ir)
    // {
    //     cout << *ir << endl;
    //     Parse *parse = new Parse(*ir);
    //     result = parse->processFile();
    //     cout << endl;
    // }

    // for (auto it = result.begin(); it != result.end(); ++it) {
    //     t.add(*it);
    // }

    // while (true) {
    //     string word;
    //     cout << "Please enter a word ..." << endl;
    //     cin >> word;
    //     if (word == "exit") {
    //         break;
    //     }
    //     if (t.find(word)) {
    //         cout << ":) Found " << word;
    //     } else {
    //         cout << ":( NOT Found";
    //     }
    //     cout << endl;
    // }
    return 0;
}
