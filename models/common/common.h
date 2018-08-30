#ifndef COMMON_H
#define COMMON_H

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Document {
    int idDocument;
    unsigned short int idFile;
    int start;
    int end;
};

struct WordDoc {
    unsigned short int pagerank;
    unsigned int idDocument;

    WordDoc(unsigned short int idDocument) {
        this->idDocument = idDocument;
        pagerank = 1;
    }

    int inc(int n = 1) {
        pagerank += n;
        return pagerank;
    }
};

struct Word {
    unsigned short int idFile;
    int start;
    // int end;
    // string content;
};

#endif // COMMON_H
