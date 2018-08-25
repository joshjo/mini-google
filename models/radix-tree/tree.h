#ifndef TREE_H
#define TREE_H
#include "Node.h"

class Tree {
public:
    Tree() {
        // root = 0;
        root = new Node("", false);
    }

    void find(
            char * str,
            Node * & node,
            Node * & parent,
            size_t & position
        ) {
        // cout << "pos: " << p(str[0]) << endl;
        position = 0;
        node = root->sons[p(str[position])];
        parent = root;
        // cout << "node: " << node << endl;

        // // root
        while (node) {
            position += 1;
            parent = node;
            node = root->sons[p(str[position])];
        }
        return;
    }

    void add (char * str) {
        if ( ! root) {
            root = new Node(str, true);
            return;
        }
        Node * node;
        Node * parent;
        size_t position;
        size_t strSize = strlen(str);
        find(str, node, parent, position);
        char * substr;
        cout << strSize << endl;
        cout << position << endl;
        cout << str << endl;
        sprintf(substr, "%.*s", 3, str + 0);

        // node = new Node(str, true);
        // node->parent = parent;
        // cout << "position: " << position << endl;
    }

    void print (Node * & node) {
        if ( ! node) {
            return;
        }
        cout << '"' << node->str << '"' << endl;

        for (size_t i = 0; i < ALPHABET_LENGTH; i += 1) {
            print(node->sons[i]);
        }
    }

    void print () {
        print(root);
    }
private:
    Node * root;
};

#endif // TREE_H
