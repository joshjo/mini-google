#ifndef COMMON_H
#define COMMON_H

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <vector>
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
    unsigned int start;

    WordDoc() {
        pagerank = 0;
        start = 0;
    }

    WordDoc(int & start) {
        this->start = start;
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
