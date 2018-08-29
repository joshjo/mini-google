#ifndef COMMON_H
#define COMMON_H

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <vector>

using namespace std;

struct Document {
    int idDocument;
    unsigned short int idFile;
    int start;
    int end;
};

struct WordDoc {
    unsigned short int pagerank;
    unsigned short int idFile;

    WordDoc(unsigned short int idFile) {
        this->idFile = idFile;
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
