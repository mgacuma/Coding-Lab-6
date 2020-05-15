#include<iostream>
#include<string>
#include<vector>
#include <map>

#include "fileIOs_wordPairs.h"

using namespace std;

int main() {

    wordPairs wdPair;
    vector<string> sentences;
    string fname = "C:\\Users\\Miguel\\source\\repos\\Coding Lab 6\\Coding Lab 6\\Text.txt";

    map< pair< string, string>, int> map;
    

    wdPair.sentenceSplitter(fname, sentences);
    wdPair.wordpairMapping(sentences, map);
    




    return 0;
}
