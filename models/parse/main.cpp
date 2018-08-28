#include "Parse.h"
//#include <vector>
int main()
{
	//C:\Users\SLLT-24\Downloads\raw.es
	Parse *parse = new Parse("C:/Users/SLLT-24/Downloads/raw.es");//spanishText_10000_15000
	vector<Word> list = parse->processFile();
	for(int i = 0; i < list.size(); i++)
	{
		cout << "IdFile: " << list.at(i).idFile << " Content: " << list.at(i).content ;
		cout << " Pos: " << list.at(i).start << " - "  << list.at(i).end << endl;
	}
	return 0;
}