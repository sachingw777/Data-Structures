#include <iostream>
using namespace std;
#include "Trie.h"
#include <vector>


int main(){
	Trie t;
	t.insertWord("and");
	t.insertWord("are");
	t.insertWord("dot");

	cout << t.search("are") << endl;

	t.removeWord("are");
	cout << t.search("are") << endl;

/* 
//pattern matching
	Trie t;
    int N;
    cin >> N;
    string pattern;
    vector<string> vect;
    for (int i=0; i < N; i++) {
        string word;
        cin >> word;
        vect.push_back(word);
    }
    cin >> pattern;
    if (t.patternMatching(vect, pattern)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    */
}