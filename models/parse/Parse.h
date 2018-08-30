#pragma once
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/foreach.hpp>
#include <boost/bimap.hpp>
#include <time.h>
#include "../common/common.h"

using namespace std;

struct cmp
{
    template<class T>
    bool operator()(T const &a, T const &b) const { return a > b; }
};

//Struct Document

class Parse
{
private:
    string pathDocuments;
    int countFiles;
    map<int, string> files;
    map<int, Document*> documents;
    size_t pos;
    string word;
    map<string *, WordDoc *> pagerank;
    Tree * t;

    // vector<Word *> words;

    string removeCharacter(string word)
    {
        string newWord = "";
        for (int i = 0 ; i < word.length() ; i ++)
        {
            unsigned char charAt = word[i];
            int c = (int)charAt;

            if ((c <= 57 && c >= 48) || (c <= 122 && c >= 97) || (c <= 90 && c >= 65))
            {
                newWord += toupper(c);
            }
            else if( c == 13)
            {
                newWord += toupper(c);
            }
            else if (c == 225 || c == 226 || c == 227 || c == 228 || c == 230 || c == 224 || c==229) {
                    newWord += "A";
                }
            else if (c == 233 || c == 234 || c == 235 || c == 201 || c == 232) {
                newWord += "E";
            }
            else if (c == 236 || c == 237) {
                newWord += "I";
            }
            else if(c == 210 || c == 211 || c == 243) {
                newWord += "O";
            }
            else if ((c <= 220 && c >= 217) || (c <= 252 && c >= 249))
            {
                newWord += "U";
            }
            else if (c == 199 || c == 212 || c == 231)
            {
                newWord += "C";
            }
            else if (c == 209)
            {
                newWord += "N";
            }
            else if (c == 181)
            {
                newWord += "U"; //micro
            }
            else
            {
                /*if ((c <= 47 && c >= 33) || (c <= 63 && c >= 58) || (c <= 96 && c >= 91) || (c <= 126 && c >= 123) || (c <= 159 && c >= 156) | (c <= 180 && c >= 166) || (c <= 188 && c >= 184) || (c <= 197 && c >= 191)
                    || (c <= 208 && c >= 202) || (c <= 223 && c >= 213) || (c <= 255 && c >= 244) || (c <= 242 && c >= 238) || (c == 200) || c == 183 || c == 161 || c == 160)
                {
                    newWord += " ";
                }
                cout << word << "-" << i << "ascii: " << c << endl;*/

                //Caracteres en blanco
                /*else if (c == 189 || c == 164)
                {
                    newWord += " ";//"�il"  //"�,"
                }
                else if (c == 163 || c == 198 || c == 230 || c == 64)
                {
                    newWord += " "; //�tla  230 198         //@ 64 //163 �
                }
                else if (c == 165)
                {
                    newWord += " ";//� 165
                }
                else if (c == 182)
                {
                    newWord += " ";//* 182
                }
                else if (c == 162)
                {
                    newWord += " ";//% 162
                }
                else if (c == 190)
                {
                    newWord += " ";// �
                }*/
            }


        }
        return newWord;
    };

    int getInformation(string delimiter, string line)
    {
        unsigned int ini = line.find(delimiter);
        ini = ini + delimiter.length() + 2; // = + "
        line.erase(0, ini);
        unsigned int end = line.find("\"");
        string result = line.substr(0, end);

        return stoi(result);
    };

    vector<string> obtenerDirectorio()
    {
        vector<string> g1;
        // g1.push_back("test");
        // g1.push_back("spanishText_15000_20000");
        // g1.push_back("spanishText_20000_25000");
        // g1.push_back("spanishText_25000_30000");
        // g1.push_back("spanishText_40000_45000");
        // g1.push_back("spanishText_45000_50000");
        // g1.push_back("spanishText_70000_75000");
        // g1.push_back("spanishText_90000_95000");
        // g1.push_back("spanishText_110000_115000");
        // g1.push_back("spanishText_120000_125000");
        // g1.push_back("spanishText_180000_185000");
        // g1.push_back("spanishText_185000_190000");
        // g1.push_back("spanishText_200000_205000");
        // g1.push_back("spanishText_205000_210000");
        // g1.push_back("spanishText_210000_215000");
        // g1.push_back("spanishText_225000_230000");
        // g1.push_back("spanishText_230000_235000");
        // g1.push_back("spanishText_260000_265000");
        // g1.push_back("spanishText_265000_270000");
        // g1.push_back("spanishText_270000_275000");
        // g1.push_back("spanishText_270000_275000");
        // g1.push_back("spanishText_285000_290000");
        // g1.push_back("spanishText_305000_310000");
        // g1.push_back("spanishText_310000_315000");
        // g1.push_back("spanishText_315000_320000");
        // g1.push_back("spanishText_320000_325000");
        // g1.push_back("spanishText_325000_330000");
        // g1.push_back("spanishText_330000_335000");
        // g1.push_back("spanishText_335000_340000");
        // g1.push_back("spanishText_340000_345000");
        // g1.push_back("spanishText_345000_350000");
        // g1.push_back("spanishText_350000_355000");
        // g1.push_back("spanishText_355000_360000");
        // g1.push_back("spanishText_360000_365000");
        // g1.push_back("spanishText_365000_370000");
        // g1.push_back("spanishText_370000_375000");
        // g1.push_back("spanishText_375000_380000");
        // g1.push_back("spanishText_380000_385000");
        // g1.push_back("spanishText_385000_390000");
        // g1.push_back("spanishText_390000_395000");
        // g1.push_back("spanishText_395000_400000");
        // g1.push_back("spanishText_400000_405000");
        // g1.push_back("spanishText_405000_410000");
        // g1.push_back("spanishText_410000_415000");
        // g1.push_back("spanishText_415000_420000");
        // g1.push_back("spanishText_420000_425000");
        // g1.push_back("spanishText_425000_430000");
        // g1.push_back("spanishText_430000_435000");
        // g1.push_back("spanishText_435000_440000");
        // g1.push_back("spanishText_440000_445000");
        // g1.push_back("spanishText_445000_450000");
        // g1.push_back("spanishText_450000_455000");
        // g1.push_back("spanishText_455000_460000");
        // g1.push_back("spanishText_460000_465000");
        // g1.push_back("spanishText_465000_470000");
        // g1.push_back("spanishText_470000_475000");
        g1.push_back("spanishText_475000_480000");
        g1.push_back("spanishText_480000_485000");
        return g1;
    };

    void readFile(int idFile, string nameFile)
    {
        // unordered_map<string, WordDoc *> tempMap;
        int start, initLine, spaces, idDocument;
        ifstream inputFile;
        inputFile.open(pathDocuments + "/" + nameFile);
        if (inputFile)
        {
            cout << "File Found : " << nameFile << endl;
            string line = "";
            string startLine = "<doc";
            string endLine = "</doc>";
            Document *tempDoc = NULL;
            for (string line; getline(inputFile, line); )
            {
                start = (int)inputFile.tellg() - line.length() - 1;
                if (line.find(startLine) != string::npos)
                {
                    tempDoc = new Document();
                    idDocument = getInformation("id", line);
                    tempDoc->idDocument = idDocument;
                    tempDoc->start = start;
                    tempDoc->idFile = idFile;

                }
                else if (line.find(endLine) != string::npos)
                {
                    tempDoc->end = inputFile.tellg();
                    documents.insert(make_pair(tempDoc->idDocument, tempDoc));
                }
                else
                {
                    pos = 0;
                    word = "";
                    string temp;

                    initLine = start;
                    spaces = 0;
                    while ((pos = line.find(" ")) != string::npos) {
                        word = line.substr(0, pos);
                        line.erase(0, pos + 1);
                        temp = removeCharacter(word);
                        if (temp.length() > 1) {
                            t->add(temp, idDocument, start);
                        }
                    }
                }
            }
            string word;
            while (inputFile >> word)
            {
                removeCharacter(word);

            }
        }
        else
        {
            cout << "File not Found" << endl;
        }
    };

public:
    void find(string word) {
        vector<string> words;
        boost::split(words, word, boost::is_any_of(" "));
        unordered_map <int, unsigned short int> directories;
        unordered_map <int, unsigned short int> pageranks;

        unordered_map <int, unsigned short int> intersections;

        unordered_map <int, vector<int> > positions;

        clock_t tStart = clock();

        int size = words.size();

        for (auto it = words.begin(); it != words.end(); it++) {
            Node * node;
            bool found = t->find(*it, node);
            // cout << "word: " << (*it) << endl;
            if (found) {
                for (auto it = node->directory.begin(); it != node->directory.end(); it++) {
                    // cout << "idDocument: " << it->first << endl;
                    int idDocument = it->first;
                    directories[idDocument] += 1;
                    pageranks[idDocument] += it->second.pagerank;
                    positions[idDocument].push_back(it->second.start);
                }
            }
        }

        for (auto it = directories.begin(); it != directories.end(); it++) {
            int idDocument = it->first;
            if (it->second == size) {
                intersections[idDocument] += pageranks[idDocument];
            }
        }
        double end = (double)(clock() - tStart) / CLOCKS_PER_SEC;

        vector <pair <unsigned short int, int> > result;

        for (auto it = intersections.begin(); it != intersections.end(); it++) {
            result.push_back(*new pair<unsigned short int, int> (it->second, it->first));
        }

        sort(result.begin(), result.end(), cmp());

        // vector <pair <int, unsigned short int> result (
        //     intersections.begin(), intersections.end())

        // sort(result.begin(), result.end(), [](auto &left, auto &right) {
        //     return left.second < right.second;
        // });
        // cout << "=== resultado ===" << endl;
        for (auto it = result.begin(); it != result.end(); it++) {
            cout << "idDocument: " << it->first << " - " << it->second << endl;
            cout << "positions: " << endl;
            auto range = positions.equal_range(it->second);
            vector<int> pos = range.first->second;
            for (int i = 0; i < pos.size(); i++) {
                cout << pos[i] << " - ";
            }
            cout << endl;
        }

        printf("Time taken: %.8fs\n", end);

        // Node * node;
        // bool found = t->find(word, node);

        // if (found) {
        //     for (auto it = node->directory.begin(); it != node->directory.end(); it++) {
        //         cout << "idDocument: " << it->first->idDocument << " - " << it->second << endl;
        //     }
        // } else {
        //     cout << "buuuuuu :(" << endl;
        // }

    }

    Parse(string pathDirectory)
    {
        this->pos = 0;
        this->pathDocuments = pathDirectory;\
        this->t = new Tree();
    };

    void processFile()
    {
        vector<string> listado = obtenerDirectorio();
        for (int i = 0; i <listado.size(); i++)
        {
            countFiles++;
            files.insert(make_pair(countFiles, listado.at(i)));
            readFile(countFiles, listado.at(i));
        }
    };
    ~Parse();
};

