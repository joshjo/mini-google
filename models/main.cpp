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

void mainMenu() {
    cout << "  Type one of the following options " << endl;
    cout << "  1. Make a search " << endl;
    cout << "  2. Show a document " << endl;
    cout << "  0. Exit " << endl;
}

void searchMenu(int next, int prev) {
    cout << "=> Type one of the following options " << endl;
    if (next > 0) {
        cout << "1. Next page " << endl;
    }
    if (prev > 0) {
        cout << "2. Prev page " << endl;
    }
    cout << "0. Back " << endl;
}

int main(int argc, char *argv[]) {

    Parse *parse = new Parse("../../files/");
    parse->processFile();
    int prev, next, total;
    double time;

    cout << "====================================" << endl;
    cout << "   (⌐■_■)  ** ALTAVISTA ** (⌐■_■)" << endl;
    cout << "====================================" << endl;

    while (true) {
        string option;
        string word;
        mainMenu();
        cout << endl << "Option >> ";
        getline(cin, option);
        if (option == "1") {
            string suboption;
            prev = 0;
            next = 0;
            total = 0;
            time = 0;
            int start = 0;
            bool firstTime = true;
            while(true) {
                if (firstTime) {
                    cout << "SEARCH >> ";
                    getline(cin, word);
                    firstTime = false;
                }


                vector <Result> results;
                parse->find(word, results, total, next, prev, time, start);
                for (int i = 0; i < results.size(); i++) {
                    cout << " === RESULT === " << endl;
                    cout << "ID DOCUMENT: ";
                    cout << results[i].docId << endl;
                    cout << "TITLE: ";
                    cout << results[i].title << endl;
                    cout << "PREVIEW: ";
                    cout << results[i].preview << endl;
                    cout << endl;
                }
                cout << "About: " << total << " results (" << time << " seconds)" << endl << endl;

                if (total == 0) {
                    start = 0;
                    cout << "¯\\_(꘠ヘ꘠)_/¯" << endl << " Sorry. We don't find your query. Try with the following options: " << endl;
                    firstTime = true;
                    continue;
                }

                searchMenu(next, prev);
                getline(cin, suboption);
                if (suboption == "1" && next > 0) {
                    start = next;
                } else if (suboption == "2" && prev > 0) {
                    start = prev;
                } else {
                    break;
                }
            }
        } else if (option == "2") {
            string docId;
            cout << "DOCUMENT ID >> ";
            getline(cin, docId);
            if (all_of(docId.begin(), docId.end(), ::isdigit)) {
                int docIdInt = atoi(docId.c_str());
                Document * doc = parse->getDocument(docIdInt);
                if (doc) {
                    cout << "TITLE: " << endl;
                    cout << doc->title << endl;
                    cout << "CONTENT: " << endl;
                    cout << parse->getText(docIdInt, doc->start, doc->end);
                    cout << endl << endl;
                }
            }


        } else if (option == "0") {
            break;
        } else {
            cout << endl << "¯\\_(ツ)_/¯ Invalid option. Please try again ¯\\_(ツ)_/¯ " << endl << endl;
        }
    }

    return 0;
}
