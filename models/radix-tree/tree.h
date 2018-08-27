#ifndef TREE_H
#define TREE_H
#include "node.h"

class Tree {
private:
    Node * root;
    bool shouldPrint;
public:
    Tree() {
        // string str = "";
        // root = new Node(str, false);
        root = 0;
        shouldPrint = false;
    }

    void printSons (Node * & node) {
        cout << "*** node: " << node << " ***" << endl;
        for (int i = 0; i < ALPHABET_LENGTH; i++) {
            if (node->sons[i]) {
                cout << "i: " << c(i) << " = " << node->sons[i] << endl;
            }
        }
    }

    void printSons() {
        // printSons(root->sons[p('H')]);
        printSons(root);
    }

    bool find(string str) {
        size_t position = 0;
        Node * node = root;
        size_t result;

        if (node) {
            result = node->contains(str, position);
            cout << "result: " << result << endl;
            cout << "position: " << position << endl;
            if (position == )
        }
    }

    size_t find(
            string & str,
            Node * & node,
            Node * & parent,
            size_t & position
        ) {
        position = 0;
        parent = 0;
        node = root;
        size_t result;
        while (node) {
            result = node->contains(str, position);
            if (shouldPrint) {
                cout << "str: " << str << endl;
                cout << "result: " << result << endl;
                cout << "pos: " << position << endl;
            }
            if (result == SPLIT_1) {
                str = str.substr(position);
                Node * next = node->sons[p(str[0])];

                if (shouldPrint) {
                    printSons(node);
                    cout << "=> node: " << node->str << endl;
                    cout << "next: " << next << " ";
                }

                if (next) {
                    if (shouldPrint) {
                        cout << "[" << next->str << "]";
                    }
                    parent = node;
                    node = next;
                    if (shouldPrint) cout << endl;
                } else {
                    if (shouldPrint) cout << endl;
                    break;
                }
            } else if (result == SPLIT_2) {
                break;
            } else if ( ! result ) {
                break;
            } else if ( result == 3) {
                break;
            } else if ( result == 4 ) {
                break;
            }
        }
        return result;
    }

    void add (string str) {
        // if (str == "HELLO") {
        //     shouldPrint = true;
        // }
        if ( ! root) {
            root = new Node(str, true);
            return;
        }
        Node * node;
        Node * parent;
        size_t position;

        size_t kase = find(str, node, parent, position);
        if (shouldPrint) {
            cout << "+++: " << str << endl;
            cout << "kase: " << kase << endl;
            cout << "node: " << node->str << " - " << node << endl;
            cout << "parent: " << parent << endl;
        }
        if (kase == NOT_FOUND) {
            createEmptyRoot(str);
        } else if (kase == SPLIT_2) {
            splitNode(node, str, position);
        } else if (kase == SPLIT_1) {
            // cout << "split 1" << endl;
            createNode(node, str);
        } else if (kase == INSIDE) {
            createNode(node, str, position);
        } else if (kase == FOUND) {
            node->isWord = true;
        }

    }

    void graphviz(Node * & node, string & tree) {
        if ( ! node) {
            return;
        }
        string name;
        char ss[100];
        sprintf(ss, "\"%p\"", node);
        name = ss;
        if (node->parent) {
            string parentStr = "\"\"";

            if (node->parent->str != "") {
                char sp[100];
                sprintf(sp, "\"%p\"", node->parent);
                parentStr = sp;
            }

            tree += parentStr + " -> " + name + "\n";
        }
        if (node->isWord) {
            tree += name + " [" + "color = cyan style = filled label = " + node->str + "]\n";
        } else if(node->str != "") {
            tree += name + " [" + "label = " + node->str + "]\n";
        }

        for (size_t i = 0; i < ALPHABET_LENGTH; i += 1) {
            graphviz(node->sons[i], tree);
        }
    }

    string graphviz(){
        string str = "digraph G {\n";
        string tree = "";
        graphviz(root, tree);
        str += tree + "}";
        return str;
    }


    void print (Node * & node) {
        if ( ! node) {
            return;
        }
        cout << '"' << node->str << '"' << "(" << node->isWord << ")";

        if (node->parent) {
            cout << " >- (" << node->parent->str << ")";
        } else {
            cout <<  " >- root";
        }
        cout << endl;

        for (size_t i = 0; i < ALPHABET_LENGTH; i += 1) {
            print(node->sons[i]);
        }
    }

    void print () {
        print(root);
    }

private:
    void createEmptyRoot(string & str) {
        if (root->str != "") {
            Node * tmp = root;
            root = new Node();
            root->sons[p(tmp->str[0])] = tmp;
            tmp->parent = root;
        }

        Node * newNode = new Node(str, true);
        root->sons[p(str[0])] = newNode;
        newNode->parent = root;
    }
    void createNode(Node * & node, string & str, size_t position) {
        string res = node->reverseCut(position);
        Node * newParent = new Node(res, true);
        Node * grandparent = node->parent;
        if (node == root) {
            root = newParent;
        } else {
            grandparent->sons[p(node->str[0])] = 0;
            grandparent->sons[p(newParent->str[0])] = newParent;
        }
        newParent->parent = grandparent;
        newParent->sons[p(node->str[0])] = node;
        node->parent = newParent;
    }

    void createNode(Node * & node, string & str) {
        Node * newNode = new Node(str, true);
        node->sons[p(str[0])] = newNode;
        newNode->parent = node;
    }

    void splitNode(Node * & node, string & str, size_t position) {
        if (shouldPrint) cout << "splitting: " << (node == root) << endl;
        if (shouldPrint) cout << "node: " << node->parent->str << endl;
        char nodeIndex = node->str[0];
        string res = node->reverseCut(position);
        Node * newParent = new Node(res, false);
        Node * parent = node->parent;
        if (node == root) {
            root = newParent;
        } else {
            // if (shouldPrint) {
            //     cout << "^ node" << node->parent->str << endl;;
            //     return;
            // }
            parent->sons[p(nodeIndex)] = 0;
            parent->sons[p(newParent->str[0])] = newParent;
        }
        newParent->parent = node->parent;

        if (shouldPrint) {
            cout << "node->parent: " << node->parent->str << endl;
            cout << "newParent->parent: " << newParent->parent->str << endl;
        }
        newParent->sons[p(node->str[0])] = node;
        node->parent = newParent;


        string substr = str.substr(position, str.size());
        Node * second = new Node(substr, true);
        newParent->sons[p(substr[0])] = second;
        second->parent = newParent;

        // node->isWord = false;
    }

};

#endif // TREE_H
