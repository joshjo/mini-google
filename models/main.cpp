#include <iostream>

#include "radix-tree/tree.h"

using namespace std;


int main(int argc, char *argv[]) {
    // string str = "HILL";
    // string str = "HI";
    // Node * node = new Node(str);
    // cout << node->cut(1) << endl;
    // cout << node->str << endl;
    // cout <<
    // // char * substr = trim(str, 0);
    // // cout << "substr: " << substr << endl;
    // // cout << int('0') << " - " << int('1') << " - " << int('9') << endl;
    string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    Tree t;
    for (int i = 0; abc.size() > 0; i += 1) {
        t.add(abc);
        abc = abc.substr(0, abc.size() - 1);
    }

    t.add("ANA");
    t.add("BERTHA");
    t.add("AH");
    t.add("AIRPLANE");
    t.add("AIR");
    t.add("AM");
    t.add("ILL");
    t.add("IRON");
    t.add("I");
    t.add("ILLNESS");
    t.add("INCLUDE");
    t.add("INSIDE");
    t.add("HILL");
    t.add("HI");
    t.add("HELLO");

    t.add("HARD");
    t.add("HARM");
    t.add("HARMFUL");
    t.add("HORSE");
    t.add("HOUR");
    t.add("HUR");
    t.add("ABCDEFGHIJKLMNOPQRSTUVWXYZ");

    // t.printSons();
    // // char * substr;
    // // sprintf(substr, "%.*s", 3, str + 0);
    // // cout << str.substr(1) << endl;
    // // cout << strlen(substr) << endl;
    // t.print();
    cout << t.graphviz() << endl;
    // // cout << char(65) << endl;
    // // string str = "HELLO";
    // // cout << str.substr(1, 2) << endl;
    //
    // cout << p('Z') << endl;
    return 0;
}
