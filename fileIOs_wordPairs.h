#ifndef FILEIOS_WORDPAIRS_H_
#define FILEIOS_WORDPAIRS_H_

#include<vector>
#include<string>
#include<map>

using namespace std;


class wordPairs {
public:
	bool sentenceSplitter(string& fname, vector<string>& sentences);
	bool wordpairMapping(vector<string>& sentences, map< pair< string, string>, int>& wordpairFreq_map);
	bool freqWordpairMmap(map< pair< string, string>, int>& wordpairFreq_map, multimap< int, pair<string, string> > &freqWordpair_mmap );
	void printWordpairs(multimap<int, pair<string, string> > &freqWordpair_multimap, string outFname, int topCnt, int botCnt);

	vector<string> sentences;

};



#endif
