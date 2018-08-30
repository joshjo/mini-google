#pragma once
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/foreach.hpp>
#include <boost/bimap.hpp>
#include "../common/common.h"

using namespace std;
bool cmp(pair<int, unsigned short int> & a, pair<int, unsigned short int> & b) {
    return b.second > a.second;
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

	//Variables constantes
	const string startDoc= "<doc";
	const string endDoc = "</doc>";
	const string delimiterId = "id";
	
	//ofstream outputFile;

	void initStopWords()
	{
		ifstream stopFile;
		stopFile.open("stopwords");
		string sw;
		while( stopFile >> sw)
		{
			stopWords.insert(sw);
			
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


	int getInformation(string delimiter, string line)
	{
		size_t pos = line.find(delimiter) + delimiter.length() + 2;
		line.erase(0, pos);
		pos = line.find("\"");
		return stoi(line.substr(0, pos));
	};

	void readFile(int idFile, string nameFile)
	{
        int start, idDocument;
		ifstream inputFile;
		inputFile.open(pathDocuments + nameFile);
		if (inputFile)
		{
			//outputFile  << pathDocuments << nameFile << endl;
			cout << "File Found" << endl;
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
					idDocument = getInformation(delimiterId, line);
                    tempDoc->idDocument = idDocument;
					tempDoc->start = start;
					tempDoc->idFile = idFile;
					cout << "Leyendo documento " << tempDoc->idDocument;

				}
				else if (line.find(endDoc) != string::npos)
				{
					//Add document
					tempDoc->end = inputFile.tellg();
					documents.insert(make_pair(tempDoc->idDocument, tempDoc));
					cout << " Fin de lectura" << tempDoc->idDocument << endl;

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
						if(a == stopWords.end() && temp.length() > 0)
						{	
							/*pos = (int)readLine.tellg();
							Word * objWord = new Word();
							objWord->idFile = idFile;
							objWord->start = (pos > 0)? pos - temp.length() + start: start;
							*/
						t->add(temp, idDocument);
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
		g1.push_back("spanishText_10000_15000");
        /*g1.push_back("spanishText_15000_20000");
		g1.push_back("spanishText_20000_25000");
		g1.push_back("spanishText_25000_30000");
		g1.push_back("spanishText_40000_45000");
		g1.push_back("spanishText_45000_50000");
		g1.push_back("spanishText_70000_75000");
		g1.push_back("spanishText_90000_95000");
		g1.push_back("spanishText_110000_115000");
		g1.push_back("spanishText_120000_125000");
		g1.push_back("spanishText_180000_185000");
		g1.push_back("spanishText_185000_190000");
		g1.push_back("spanishText_200000_205000");
		g1.push_back("spanishText_205000_210000");
		g1.push_back("spanishText_210000_215000");
		g1.push_back("spanishText_225000_230000");
		g1.push_back("spanishText_230000_235000");
		g1.push_back("spanishText_260000_265000");
		g1.push_back("spanishText_265000_270000");
		g1.push_back("spanishText_270000_275000");
		g1.push_back("spanishText_270000_275000");
		g1.push_back("spanishText_285000_290000");
		g1.push_back("spanishText_305000_310000");
		g1.push_back("spanishText_310000_315000");
		g1.push_back("spanishText_315000_320000");
		g1.push_back("spanishText_320000_325000");
		g1.push_back("spanishText_325000_330000");
		g1.push_back("spanishText_330000_335000");
		g1.push_back("spanishText_335000_340000");
		g1.push_back("spanishText_340000_345000");
		g1.push_back("spanishText_345000_350000");
		g1.push_back("spanishText_350000_355000");
		g1.push_back("spanishText_355000_360000");
		g1.push_back("spanishText_360000_365000");
		g1.push_back("spanishText_365000_370000");
		g1.push_back("spanishText_370000_375000");
		g1.push_back("spanishText_375000_380000");
		g1.push_back("spanishText_380000_385000");
		g1.push_back("spanishText_385000_390000");
		g1.push_back("spanishText_390000_395000");
		g1.push_back("spanishText_395000_400000");
		g1.push_back("spanishText_400000_405000");
		g1.push_back("spanishText_405000_410000");
		g1.push_back("spanishText_410000_415000");
		g1.push_back("spanishText_415000_420000");
		g1.push_back("spanishText_420000_425000");
		g1.push_back("spanishText_425000_430000");
		g1.push_back("spanishText_430000_435000");
		g1.push_back("spanishText_435000_440000");
		g1.push_back("spanishText_440000_445000");
		g1.push_back("spanishText_445000_450000");
		g1.push_back("spanishText_450000_455000");
		g1.push_back("spanishText_455000_460000");
		g1.push_back("spanishText_460000_465000");
		g1.push_back("spanishText_465000_470000");
		g1.push_back("spanishText_470000_475000");
		g1.push_back("spanishText_475000_480000");
		g1.push_back("spanishText_480000_485000");*/
		return g1;
	};

public:
    void find(string word) {
        vector<string> words;
        boost::split(words, word, boost::is_any_of(" "));
        unordered_map <int, unsigned short int> directories;
        unordered_map <int, unsigned short int> pageranks;

        boost::bimap<int, unsigned short int> intersections;
        // unordered_map <int, unsigned short int> intersections;



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
                    pageranks[idDocument] += it->second;
                }
            }
        }

        for (auto it = directories.begin(); it != directories.end(); it++) {
            int idDocument = it->first;
            // if (it->second == size) {
            //     //results.insert(results_bimap::value_type(
            //       //  results[idDocument], pageranks[idDocument]));
            //     // results[idDocument] += pageranks[idDocument];
            // }
        }

        // vector<pair<int, unsigned short int> > result(
        //     intersections.begin(), intersections.end());

        // sort(intersections.begin(), intersections.end());

        // cout << "=== resultado ===" << endl;
        // for (auto it = result.begin(); it != result.end(); it++) {
        //     cout << "idDocument: " << it->first << " - " << it->second << endl;
        // }

        // Node * node;
        // bool found = t->find(word, node);

        // if (found) {
        //     for (auto it = node->directory.begin(); it != node->directory.end(); it++) {
        //         cout << "idDocument: " << it->first->idDocument << " - " << it->second << endl;
        //     }
        // } else {
        //     cout << "buuuuuu :(" << endl;
        // }

    };

    string getText(int idDocument, string word)
    {
        ifstream ifs;
        //Get Obj Document  by idodcumento
        if(documents.find(idDocument) != documents.end())
        {
            Document *doc = documents.at(idDocument);
            //Get File 
            if(files.find(doc->idFile) != files.end())
            {
                string name = files.at(doc->idFile);
                //Si se tiene end  ini de word?
                ifs.open (pathDocuments + name);
                ifs.seekg(20);//(doc->start);
                int length = ifs.tellg();
                char * buffer = new char [length];
                //string buffer;
                ifs.read(buffer,length);
                string out(buffer);
                cout << "Text :" << out <<endl;
            }
        }
    };

	Parse(string pathDirectory)
	{
		this->pos = 0;
        this->pathDocuments = pathDirectory;
        this->t = new Tree();
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

