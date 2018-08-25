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

size_t firstLetter = int('0');

int p(char c) {
    /*
    A function to return the postion of a letter.
    Starts from 0 to ALPHABET_LENGTH.
    e.g.
    A = 10
    B = 11
     */
    return int(c) - firstLetter;
}

char * trim(char * str, size_t start) {
    char * substr;
    size_t size = strlen(substr);
    sprintf(substr, "%.*s", size, str + start);
    return substr;
}

class Tree;

class Node {

private:
    char * str;
    Node ** sons;
    Node * parent;
    bool isWord;
    size_t size;

public:
    Node(char const * str, bool isWord = false) {
        this->str = new char(*str);
        this->sons = new Node * [ALPHABET_LENGTH];
        this->isWord = isWord;
        this->parent = 0;
        this->size = strlen(str);
    }

    size_t contains(char * otherStr, size_t & i) {
        size_t minSize = strlen(otherStr);
        size_t result = PARTIAL;
        if (size < minSize) {
            minSize = size;
        } else {
            result = INSIDE;
        }

        if ( ! minSize || otherStr[0] != str[0]) {
            return NOT_FOUND;
        }

        for (i = 1; i < minSize; i += 1) {
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
