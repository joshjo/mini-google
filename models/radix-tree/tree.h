#ifndef TREE_H
#define TREE_H
#include "Node.h"

class Tree {
public:
    Tree() {
        root = 0;
    }

    // void find(char * str, Node * & node, Node * & parent) {
    //     Node * tmp = root;
    //     while (tmp) {
    //         if (tmp->contains(str)) {

    //         }
    //     }
    // }
    void add (char * str) {
        cout << "contains? " << root->contains(str) << endl;
    }
private:
    Node * root;
};

#endif // TREE_H
