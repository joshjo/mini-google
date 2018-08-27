#pragma once
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;
class Parse
{
private:
	ifstream inputFile;
	ofstream outputFile;
	vector<string> words;
	string removeCharacter(string word);
	void printChar();

public:
	Parse(string pathFile);
	vector<string> processFile();
	~Parse();
};

