#include "Parse.h"


int main() {
    Parse *parse = new Parse("../../../test/");//spanishText_10000_15000
    vector<Word> list = parse->processFile();
    for(int i = 0; i < list.size(); i++)
    {
        cout << "IdFile: " << list.at(i).idFile << " Content: " << list.at(i).content ;
        cout << " Pos: " << list.at(i).start << " - "  << list.at(i).end << endl;
    }

    return 0;
}
