#include <iostream>

#include "radix-tree/tree.h"
#include "parse/Parse.h"

using namespace std;


int main(int argc, char *argv[]) {
    vector<string> g1;
    g1.push_back("../../files/spanishText_10000_15000");
    // g1.push_back("../../files/spanishText_15000_20000");
    // g1.push_back("../../files/spanishText_20000_25000");
    // g1.push_back("../../files/spanishText_25000_30000");
    // g1.push_back("../../files/spanishText_40000_45000");
    // g1.push_back("../../files/spanishText_45000_50000");
    // g1.push_back("../../files/spanishText_70000_75000");
    // g1.push_back("../../files/spanishText_90000_95000");
    // g1.push_back("../../files/spanishText_110000_115000");
    // g1.push_back("../../files/spanishText_120000_125000");
    // g1.push_back("../../files/spanishText_180000_185000");
    // g1.push_back("../../files/spanishText_185000_190000");
    // g1.push_back("../../files/spanishText_200000_205000");
    // g1.push_back("../../files/spanishText_205000_210000");
    // g1.push_back("../../files/spanishText_210000_215000");
    // g1.push_back("../../files/spanishText_225000_230000");
    // g1.push_back("../../files/spanishText_230000_235000");
    // g1.push_back("../../files/spanishText_260000_265000");
    // g1.push_back("../../files/spanishText_265000_270000");
    // g1.push_back("../../files/spanishText_270000_275000");
    // g1.push_back("../../files/spanishText_270000_275000");
    // g1.push_back("../../files/spanishText_285000_290000");
    // g1.push_back("../../files/spanishText_305000_310000");
    // g1.push_back("../../files/spanishText_310000_315000");
    // g1.push_back("../../files/spanishText_315000_320000");
    // g1.push_back("../../files/spanishText_320000_325000");
    // g1.push_back("../../files/spanishText_325000_330000");
    // g1.push_back("../../files/spanishText_330000_335000");
    // g1.push_back("../../files/spanishText_335000_340000");
    // g1.push_back("../../files/spanishText_340000_345000");
    // g1.push_back("../../files/spanishText_345000_350000");
    // g1.push_back("../../files/spanishText_350000_355000");
    // g1.push_back("../../files/spanishText_355000_360000");
    // g1.push_back("../../files/spanishText_360000_365000");
    // g1.push_back("../../files/spanishText_365000_370000");
    // g1.push_back("../../files/spanishText_370000_375000");
    // g1.push_back("../../files/spanishText_375000_380000");
    // g1.push_back("../../files/spanishText_380000_385000");
    // g1.push_back("../../files/spanishText_385000_390000");
    // g1.push_back("../../files/spanishText_390000_395000");
    // g1.push_back("../../files/spanishText_395000_400000");
    // g1.push_back("../../files/spanishText_400000_405000");
    // g1.push_back("../../files/spanishText_405000_410000");
    // g1.push_back("../../files/spanishText_410000_415000");
    // g1.push_back("../../files/spanishText_415000_420000");
    // g1.push_back("../../files/spanishText_420000_425000");
    // g1.push_back("../../files/spanishText_425000_430000");
    // g1.push_back("../../files/spanishText_430000_435000");
    // g1.push_back("../../files/spanishText_435000_440000");
    // g1.push_back("../../files/spanishText_440000_445000");
    // g1.push_back("../../files/spanishText_445000_450000");
    // g1.push_back("../../files/spanishText_450000_455000");
    // g1.push_back("../../files/spanishText_455000_460000");
    // g1.push_back("../../files/spanishText_460000_465000");
    // g1.push_back("../../files/spanishText_465000_470000");
    // g1.push_back("../../files/spanishText_470000_475000");
    // g1.push_back("../../files/spanishText_475000_480000");
    // g1.push_back("../../files/spanishText_480000_485000");


    Tree t;
    // string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // for (int i = 0; abc.size() > 0; i += 1) {
    //     t.add(abc);
    //     abc = abc.substr(0, abc.size() - 1);
    // }
    //
    vector <string> words;
    // words.push_back("ANA");
    // words.push_back("BERTHA");
    // words.push_back("AH");
    // words.push_back("AIRPLANE");
    // words.push_back("AIR");
    // words.push_back("AM");
    // words.push_back("ILL");
    // words.push_back("IRON");
    // words.push_back("I");
    // words.push_back("ILLNESS");
    // words.push_back("INCLUDE");
    // words.push_back("INSIDE");
    words.push_back("HILL");
    words.push_back("HI");
    words.push_back("HELLO");

    // t.add("ANA");
    // t.add("BERTHA");
    // t.add("AH");
    // t.add("AIRPLANE");
    // t.add("AIR");
    // t.add("AM");
    // t.add("ILL");
    // t.add("IRON");
    // t.add("I");
    // t.add("ILLNESS");
    // t.add("INCLUDE");
    // t.add("INSIDE");
    // t.add("HILL");
    // t.add("HI");
    // t.add("HELLO");

    // t.add("HARD");
    // t.add("HARM");
    // t.add("HARMFUL");
    // t.add("HORSE");
    // t.add("HOUR");
    // t.add("HUR");
    // t.add("ABCDEFGHIJKLMNOPQRSTUVWXYZ");

    // t.printSons();
    // // char * substr;
    // // sprintf(substr, "%.*s", 3, str + 0);
    // // cout << str.substr(1) << endl;
    // // cout << strlen(substr) << endl;
    // t.print();
    // cout << t.find("HI") << endl;
    // cout << t.graphviz() << endl;
    vector<string> result;
    // for (auto ir = g1.crbegin(); ir != g1.crend(); ++ir)
    // {
    //     cout << *ir << endl;
    //     Parse *parse = new Parse(*ir);//spanishText_10000_15000
    //     result = parse->processFile();
    //     cout << endl;
    // }

    for (auto it = result.begin(); it != result.end(); ++it) {
        t.add(*it);
    }
    // cout << t.graphviz() << endl;
    //
    // string str = "HELLO";
    // cout << str.substr(2);
    return 0;
}
