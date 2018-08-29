#pragma once
#include "../common/common.h"

using namespace std;
//Struct Document

class Parse
{
private:
	string pathDocuments;
	int countFiles;
	map<int, string> files;
	map<int, Document*> documents;
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
					newWord += " "; //�tla  230 198			//@ 64 //163 �
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

	void readFile(int idFile, string nameFile)
	{
		ifstream inputFile;
		inputFile.open(pathDocuments + "/" + nameFile);
		if (inputFile)
		{
			cout << "File Found" << endl;
			string line = "";
			string startLine = "<doc";
			string endLine = "</doc>";
			Document *tempDoc = NULL;
			//int count = 0;
			for (string line; getline(inputFile, line); )
			{
				//count++;
				//Get information doc
                int start = (int)inputFile.tellg() - line.length() - 1;
				if (line.find(startLine) != string::npos)
				{
					//Init Document
					tempDoc = new Document();
					tempDoc->idDocument =  getInformation("id", line);
					tempDoc->start = start;
					tempDoc->idFile = idFile;

				}
				else if (line.find(endLine) != string::npos)
				{
					//Add document
					tempDoc->end = inputFile.tellg();
					documents.insert(make_pair(tempDoc->idDocument, tempDoc));

				}
				else
				{
					size_t pos = 0;
					string word;
					string temp;

					int initLine = start;
                    int spaces = 0;
					while ((pos = line.find(" ")) != string::npos) {
						word = line.substr(0, pos);
						line.erase(0, pos + 1);
						temp = removeCharacter(word);
						//count += pos;
						if (temp.length() > 0)
						{
							Word * objWord = new Word();
							objWord->idFile = idFile;
							objWord->start = initLine + spaces;
							initLine += pos;
							objWord->end = initLine + spaces;
							objWord->content = temp;
                            words.insert(pair<string, Word *> (temp, objWord));
							// words.push_back(objWord);
                            initLine += 1;
                            spaces = 0;
						} else {
                            spaces += 1;
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

	vector<string> obtenerDirectorio()
	{
		vector<string> g1;
		// g1.push_back("test");
        // g1.push_back("spanishText_15000_20000");
		g1.push_back("spanishText_15000_20000");
		g1.push_back("spanishText_20000_25000");
		g1.push_back("spanishText_25000_30000");
		g1.push_back("spanishText_40000_45000");
		g1.push_back("spanishText_45000_50000");
		g1.push_back("spanishText_70000_75000");
		g1.push_back("spanishText_90000_95000");
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
		// g1.push_back("spanishText_475000_480000");
		// g1.push_back("spanishText_480000_485000");
		return g1;
	};

public:
    multimap<string, Word *> words;

	Parse(string pathDirectory)
	{
		this->pathDocuments = pathDirectory;
	};

    void someContent(string & str) {
        auto search = words.equal_range(str);

        for (auto it = search.first; it != search.second; it++) {
            ifstream file(pathDocuments + "/" + files[it->second->idFile]);

            int start = it->second->start;
            int end = it->second->end + 30;
            file.seekg(start);
            std::string s;
            s.resize(end - start);
            file.read(&s[0], end - start);
            cout << files[it->second->idFile] << ": " << s << endl;
            file.close();
        }
    }

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

