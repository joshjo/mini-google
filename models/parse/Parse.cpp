#include "Parse.h"

string empty = "";

using namespace std;
Parse::Parse(string pathFile)
{

	inputFile.open(pathFile);
	outputFile.open("spanishTextOutput");

}

vector<string> Parse::processFile()
{
	try
	{
		if (inputFile)
		{
			cout << "File Found" << endl;
			//printChar();
			string word;
			while (inputFile >> word)
			{
				if (outputFile.is_open())
				{
					words.push_back(removeCharacter(word));
					//outputFile << removeCharacter(word) + empty;
				}

			}
			//outputFile.close();
			//cout << "File output writted" << endl;
			return words;
		}
		else
		{
			cout << "File not Found" << endl;
			return words;
		}

	}
	catch (exception e)
	{
		throw std::invalid_argument("File not found");
	}
}

string Parse::removeCharacter(string word)
{
	//number 0-9 -> 48-57
	//Minusculas a - z -> 97-122
	//Mayusculas A - Z -> 33-90
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
		else if ((c <= 47 && c >= 33) || (c <= 63 && c >= 58) || (c <= 96 && c >= 91) || (c <= 126 && c >= 123) || (c <= 159 && c >= 156) | (c <= 180 && c >= 166) || (c <= 188 && c >= 184) || (c <= 197 && c >= 191)
			|| (c <= 208 && c >= 202) || (c <= 223 && c >= 213) || (c <= 255 && c >= 244) || (c <= 242 && c >= 238) || (c == 200) || c == 183 || c == 161 ||c == 160)
		{
			newWord += empty;
		}
		else
		{

			if (c == 225 || c == 226 || c == 227 || c == 228 || c == 230 || c == 224 || c==229) {
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
			else if (c == 189 || c == 164)
			{
				newWord += empty;//"½il"  //"¤,"
			}
			else if (c == 163 || c == 198 || c == 230 || c == 64)
			{
				newWord += empty; //ætla  230 198			//@ 64 //163 £
			}
			else if (c == 165)
			{
				newWord += empty;//¥ 165
			}
			else if ( c == 182)
			{
				newWord += empty;//* 182
			}
			else if (c == 162)
			{
				newWord += empty;//% 162
			}
			else if (c == 190)
			{
				newWord += empty;// ¾
			}
			else
			{
				cout << word << "-" << i << "ascii: " << c << endl;
			}


		}
	}
	return newWord;
}

void Parse::printChar()
{
	cout << "Print char" << endl;
	for (int i = 0; i <= 255; i++) {
		//fprintf(stdout, "[%d]: %c\n", i, i);
		fprintf(stdout, " %c\n", i);
	}

}
Parse::~Parse()
{
}
