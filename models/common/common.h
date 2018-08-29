#ifndef COMMON_H
#define COMMON_H

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

struct Document {
    int idDocument;
    int idFile;
    int start;
    int end;
};

struct Word {
    int idFile;
    int start;
    int end;
    string content;
};

#endif // COMMON_H
