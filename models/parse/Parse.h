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
	set<string> stopWords;
    int pageSize;

	//Variables constantes
	const string startDoc= "<doc";
	const string endDoc = "</doc>";
	const string delimiterId = "id";
	const string delimiterTitle = "title";
	const string delimiterEndDoc = "ENDOFARTICLE";

	//ofstream outputFile;

	void initStopWords()
	{
		ifstream stopFile;
		stopFile.open("parse/stopwords");
		string sw;
		while( stopFile >> sw)
		{
			stopWords.insert(sw);

		}
        auto it = stopWords.begin();
        if (it == stopWords.end()) {
            cout << "WARNING: Stopwords are not being loaded" << endl;
        }
	}

	string removeCharacter(string word)
	{
		string newWord = "";
		unsigned char charAt;
		int c;
		for (int i = 0 ; i < word.length() ; i ++)
		{
			charAt = word[i];
			c = (int)charAt;
			if((c >= 48 && c <= 57) || (c >= 65 && c <= 90)
				|| (c >= 97 && c <= 122))
				newWord += toupper(c);
			else if( c == 209 || c == 241)
				newWord += "N"; //ñ
			else if( (c >= 192 && c <= 194) || c == 196 || (c >= 224 && c <= 226) || c == 228)
				newWord += "A"; //á
			else if( (c >= 200 && c <= 203) || (c >= 232 && c <= 235) )
				newWord += "E"; //É é
			else if((c >= 204 && c <= 207) || (c >= 236 && c <= 239) )
				newWord += "I"; //í
			else if((c >= 210 && c <= 211) || c == 214 || c == 220 || (c >= 242 && c <= 244) || c == 246 || c == 252)
				newWord += "O"; //ó
			else if((c >= 217 && c <= 219) || (c >= 249 && c <= 250) )
				newWord += "U"; //ú
			 /*else
			 {
			 	cout << word << " - " << newWord << endl;
			 	cout << word[i] << "- ascii: " << c << endl;
			 	break;
			 }*/

		}
		//cout << word << "-"<< newWord << endl << endl;
		return newWord;
	};


	string getInformation(string delimiter, string line)
	{
		size_t pos = line.find(delimiter) + delimiter.length() + 2;
		line.erase(0, pos);
		pos = line.find("\"");
		return line.substr(0, pos);
	};

	void readFile(int idFile, string nameFile)
	{
        int start, idDocument;
		ifstream inputFile;
		inputFile.open(pathDocuments + nameFile);
		// inputFile.open("spanishText1000015000");
		if (inputFile)
		{
			//outputFile  << pathDocuments << nameFile << endl;
			cout << "File Found " << nameFile << endl;
			Document *tempDoc = NULL;
			//int count = 0;
			for (string line; getline(inputFile, line); )
			{
				//count++;
				//Get information doc
                start = (int)inputFile.tellg() - line.length() - 1;
				/*cout << "star line" << start << endl;
				cout << line << endl;*/
				if (line.find(startDoc) != string::npos)
				{
					//Init Document
					tempDoc = new Document();
					idDocument = stoi(getInformation(delimiterId, line));
					tempDoc->title = getInformation(delimiterTitle, line);
                    tempDoc->idDocument = idDocument;
					tempDoc->start = start + line.length(); // +1
					tempDoc->idFile = idFile;
					// cout << "Titulo"<< tempDoc->title << endl;
					// cout << "Inicio doc "<< tempDoc->start << endl;

				}
				else if (line.find(endDoc) != string::npos)
				{
					//Add document
					tempDoc->end = start - delimiterEndDoc.length() - 1; //-1 
					documents.insert(make_pair(tempDoc->idDocument, tempDoc));
					// cout << "- "<< tempDoc->end << endl;
				}
				else
				{

					//int initLine = start;
					string word, temp;
					istringstream readLine(line);
					//int posLast = line.length();
					int pos = 0;// TODO
					while (readLine >> word)
					{
						temp = removeCharacter(word);
						set<string>::iterator a = stopWords.find(temp);
						if(a == stopWords.end() && temp.length() > 1)
						{
							/*pos = (int)readLine.tellg();
							Word * objWord = new Word();
							objWord->idFile = idFile;
							objWord->start = (pos > 0)? pos - temp.length() + start: start;
							*/
                            // cout << temp << endl;
                           t->add(temp, idDocument, start);
						}
					}
				}
			}
		}
		else
		{
			cout << "File not Found" << endl;
		}
	};

	vector<string> obtenerDirectorio()
	{
		vector<string> g1;
		//g1.push_back("prueba");
		//  g1.push_back("spanishText_10000_15000");
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

public:
    string find(string word, unsigned int start = 0) {
        vector<string> words;
        string response = "{ ";
        boost::split(words, word, boost::is_any_of(" "));
        unordered_map <int, unsigned short int> directories;
        unordered_map <int, unsigned short int> pageranks;
        unordered_map <int, unsigned short int> intersections;
        unordered_map <int, vector<int> > positions;

        clock_t tStart = clock();

        int size = words.size();

        for (auto it = words.begin(); it != words.end(); it++) {
            Node * node;
            bool found = t->find(removeCharacter(*it), node);
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

        string results = "[ ";
        auto it = result.begin();
        for (; it != result.end(); it++) {
        // for (; it != result.end() && it != result.begin() + start + pageSize; it++) {
            results += " {\"docid\": " + to_string(it->second) + ",";
            auto range = positions.equal_range(it->second);
            vector<int> pos = range.first->second;
            if (pos.size()) {
                results += "\"preview\": \"" + getText(it->second, pos[0]) + "\"";
            } else {
                results.pop_back();
            }
            results += "},";
        }


        int prev = (start - pageSize) > 0 ? (start - pageSize) : 0;
        int next = (start + pageSize < results.size()) ? (start + pageSize) : 0;

        results.pop_back();
        results += "]";
        response += "\"results\": " + results + ",";
        response += "\"prev\": " + to_string(prev) + ",";
        response += "\"next\": " + to_string(next) + ",";
        response += "\"total\": " + to_string(result.size()) + ",";
        // response += "\"previous\": " + ((start - pageSize) < 0) ? "-1" : to_string(start - pageSize) + ",";

        response += "\"time\": " + to_string(end);
        response += "}";

        // Node * node;
        // bool found = t->find(word, node);

        // if (found) {
        //     for (auto it = node->directory.begin(); it != node->directory.end(); it++) {
        //         cout << "idDocument: " << it->first->idDocument << " - " << it->second << endl;
        //     }
        // } else {
        //     cout << "buuuuuu :(" << endl;
        // }
        return response;
    };

    string getText(int idDocument, int start)
    {
        ifstream ifs;
        Document * doc = documents[idDocument];
        if ( ! doc) {
            return "";
        }
        string s;
        string fileName = files[doc->idFile];
        // cout << "start: " << start << endl;

        if (fileName != "") {
            ifstream inputFile;
            inputFile.open(pathDocuments + fileName);
            int end = start + 20;
            inputFile.seekg(start);
            s.resize(end - start);
            inputFile.read(&s[0], end - start);
        }

        return escape_json(s);

        // //Get Obj Document  by idodcumento
        // if(documents.find(idDocument) != documents.end())
        // {
        //     Document *doc = documents.at(idDocument);
        //     //Get File
        //     if(files.find(doc->idFile) != files.end())
        //     {
        //         string name = files.at(doc->idFile);
        //         //Si se tiene end  ini de word?
        //         ifs.open (pathDocuments + name);
        //         ifs.seekg(start);//(doc->start);
        //         // int length = ifs.tellg();
        //         int length = 30;
        //         char * buffer = new char [length];
        //         //string buffer;
        //         ifs.read(buffer,length);
        //         string out(buffer);
        //         cout << "Text :" << out <<endl;
        //     }
        // }
    };

	Parse(string pathDirectory)
	{
		this->pos = 0;
        this->pathDocuments = pathDirectory;
        this->t = new Tree();
        this->pageSize = 10;
		initStopWords();
	};

	void processFile()
	{

		//outputFile.open("output.txt");
		vector<string> listado = obtenerDirectorio();
		for (int i = 0; i <listado.size(); i++)
		{
			countFiles++;
			files.insert(make_pair(countFiles, listado.at(i)));
			readFile(countFiles, listado.at(i));
		}
		//outputFile.close();
	};

	~Parse();
};

