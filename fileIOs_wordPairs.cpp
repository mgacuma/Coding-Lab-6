#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <utility>

using namespace std;

#include "fileIOs_wordPairs.h"
#include <set>


bool wordPairs::sentenceSplitter(string& fname, vector<string>& sentences) {
	
	bool b = false, quoteMode = false;

	ifstream in;
	string line, sentence;
	

	in.open(fname);

	if (!in.is_open()) {
		cout << "File open error" << endl;
		return b;
	}

	while (!in.eof()) {
		
		
		getline(in, line);
		//cout << line << " " << line.size() << endl << endl;

		for (int i = 0; i < line.size(); i++) {
			
			switch (line.at(i)) {
				case '"':
				{
					if (quoteMode) {
						sentence = sentence + line.at(i);
						quoteMode = false;

						if(line.at(i-1) == '.' || line.at(i - 1) == '?'){
							sentences.push_back(sentence);
							sentence.clear();
						}
						i++;
					}
					else {
						quoteMode = true;
						sentence = sentence + line.at(i);
					}
					break;
				}

				case '.': 
				{
					if (quoteMode) {
						sentence = sentence + line.at(i);
						if (line.at(i - 1) == 'y') {
							sentences.push_back(sentence);
							sentence.clear();
						}
					}

					else {
						sentence = sentence + line.at(i);

						sentences.push_back(sentence);
						sentence.clear();
						i++;
					}
					break;
				}

				case '?': 
				{
					if (quoteMode) {
						sentence = sentence + line.at(i);
					}

					else {
						sentence = sentence + line.at(i);

						sentences.push_back(sentence);
						sentence.clear();
						i++;
					}
					break;
				}

				case ':': 
				{
					if (i == line.size()-1) {
						sentence = sentence + line.at(i);
						

						sentences.push_back(sentence);
						sentence.clear();
						i++;
					}
					break;
				}

				default: {
					if (line.at(i) != '"') {
						sentence = sentence + line.at(i);
					}
				}
			}
		}
	}


	//SENTENCE TRIMMING
	
	for (int i = 0; i < sentences.size(); i++) {
		sentence = sentences.at(i);
		
		//transform(sentences.at(i).begin(),sentences.at(i).end(), sentences.at(i).begin(),[](unsigned char c) { return tolower(c); });
		
		if (sentence.at(0) == ' ') {
			sentence.erase(0, 1);
		}

		for (int j = 0; j < sentence.size(); j++) {
			if (sentences.at(i).at(j) == '.' || sentences.at(i).at(j) == '?' || sentences.at(i).at(j) == '"' || sentences.at(i).at(j) == ':' || sentences.at(i).at(j) == '\n' || sentences.at(i).at(j) == ',') {
				sentences.at(i).at(j) = ' ';
			}
		}

		int val = sentence.at(sentence.size() - 1);
		int pval = sentence.at(sentence.size() - 2);
		cout << pval << " " << val << " is the ASCII. " << endl;

	}

	

	//PRINT SENTENCES

	cout << endl << endl << "SENTENCES VECTOR" << endl << endl;
	for (int i = 0; i < sentences.size(); i++) {
		cout << i << ". " <<  sentences.at(i) << " " <<  endl;
	}

	in.close();
	b = true;
	return b;
}



bool wordPairs::wordpairMapping(vector<string>& sentences, map< pair< string, string>, int>& wordpairFreq_map){
	bool b = false;


	for (int k = 0; k < sentences.size(); k++) {
	//int k = 0;

		string sentence = sentences.at(k);
		set<string> uniqueWords;
		vector<string> words;
		string newWord;

		//Pick words out of a sentence line

		for (int i = 0; i < sentence.size(); i++) {

			if (sentence.at(i) == ' ' || sentence.at(i) == '\0'){
				if (newWord.size() != 0) {
					if (uniqueWords.count(newWord) == 0) {

						uniqueWords.emplace(newWord);
						words.push_back(newWord);
						newWord.clear();
					}
					else {
						newWord.clear();
					}
				}
			}

			else {
				newWord = newWord + sentence.at(i);
			}


		}
		

		//cout << endl;

		//Print words of the sentence

		/*for (int j = 0; j < words.size(); j++) {
			cout << words.at(j) << " " << words.size() << endl;
		}*/
		//cout << endl;
		
		//Make pairings from sentence

		for (int i = 0; i < words.size() - 1; i++) {
			for (int j = i+1; j < words.size(); j++) {
				pair<string, string> tempPair;
				string word1, word2;

				word1 = words.at(i);
				word2 = words.at(j);

				if (word1 < word2) {
					tempPair.first = word1;
					tempPair.second = word2;
				}

				else {
					tempPair.first = word2;
					tempPair.second = word1;
				}

				
				if (wordpairFreq_map.count(tempPair) == 1) {
					wordpairFreq_map.at(tempPair)++;
					
				}
				else {
					wordpairFreq_map.emplace(tempPair, 1);
					
				}

				
			}
		}
	}

	for (map< pair <string, string >, int>::iterator it = wordpairFreq_map.begin(); it != wordpairFreq_map.end(); ++it) {
		pair<string, string> key = it->first;
		cout << "< " << key.first << " , " << key.second << "> : " << it->second << endl;
	}

	this->sentences = sentences;
	
	cout << wordpairFreq_map.size() << endl;
	return b = true;
}


bool wordPairs::freqWordpairMmap(map< pair< string, string>, int>& wordpairFreq_map, multimap< int, pair<string, string> > &freqWordpair_mmap ){
	return true;
}














void wordPairs::printWordpairs(multimap<int, pair<string, string> > &freqWordpair_multimap, string outFname, int topCnt, int botCnt){

}
