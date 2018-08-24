#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string.h>
// We are not considering the ñ letter
#define ALPHABET_LENGTH 36
#define NOT_FOUND 0
#define PARTIAL 1
#define INSIDE 2

using namespace std;

class Tree;

class Node {

private:
    char * str;
    Node ** sons;
    Node * parent;
    bool isWord;
    size_t size;

public:
    Node(char const * str = "") {
        this->str = new char(*str);
        this->sons = new Node * [ALPHABET_LENGTH];
        this->isWord = true;
        this->parent = 0;
        this->size = strlen(str);
    }

    size_t contains(char * otherStr) {
        size_t minSize = strlen(str);
        size_t result = INSIDE;

        if (size < minSize) {
            result = INSIDE;
            minSize = size;
        }

        if ( ! minSize || otherStr[0] != str[0]) {
            return NOT_FOUND;
        }

        for (size_t i = 1; i < minSize; i += 1) {
            if (otherStr[i] != str[i]) {
                result = PARTIAL;
                break;
            }
        }
        return result;
    }

    friend class Tree;
};


#endif // NODE_H
