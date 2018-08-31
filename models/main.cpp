#include <iostream>

#include <boost/property_tree/json_parser.hpp>
#include "radix-tree/tree.h"
#include "parse/Parse.h"

using namespace std;

vector<string>* findSimilarWords(Tree t, string word){
    vector<string> *dictionary = new vector<string>;
    t.findOptions(word, dictionary);
    return dictionary;
}

string vectorToJson(vector<string> *list){
    string json_string = "{'words':[";
    for(int i = 0; i < list->size(); i++){
        json_string += "'"+(*list)[i]+"'";
        if(i != list->size()-1)
            json_string += ",";
    }
    json_string += "]}";
    return json_string;
}

string getNearWord(Tree t, vector<vector<string>*> *dictionary, string find_word){
    std::transform(find_word.begin(), find_word.end(),find_word.begin(), ::toupper);
    if(find_word.length() < 2)
        return "VACIO";
    return t.processMostNear(dictionary, find_word);
}

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

    // vector<vector<string>*> *dictionary = new vector<vector<string>*>();
    // t.loadData(dictionary, "../../files/differentWords.txt");
    // cout << "Loaded " << dictionary->size() << endl;
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
        parse->findSimilarWords(word);
        //string result;
        ////t.findOptions(word, &dictionary);
        //vector<string> *list = findSimilarWords(t, word);
        //cout << endl;
        //for(int i = 0; i < list->size(); i++)
        //    cout << (*list)[i] << endl;
        //cout << endl;
        //cout << vectorToJson(list) << endl;
        //delete list;
        // cout << "Levenshtein "<< endl;
        // cout << getNearWord(t, dictionary, word)<< endl;
        // cout << endl;
    }

    return 0;
}
