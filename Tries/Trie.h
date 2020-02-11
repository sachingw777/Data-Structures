#include "TrieNode.h"
#include <string>

class Trie{
	TrieNode* root;

public:
	Trie(){
		root = new TrieNode('\0');
	}

private:
	void insertWord(TrieNode *root, string word){
		if(word.size() == 0){
			root -> isTerminal = true;
			return;
		}

		int index = word[0] - 'a';
		TrieNode* child;
		if(root -> children[index] != NULL){
			child = root -> children[index];
		}else{
			child = new TrieNode(word[0]);
			root -> children[index] = child;
		}

		insertWord(child, word.substr(1));
	}

public:
	void insertWord(string word){
		insertWord(root, word);
	}

private:
    bool search(TrieNode *root, string word) {
		if(word.size() == 0){
			return root -> isTerminal;
		}

		int index = word[0] - 'a';
		TrieNode* child;
		
		if(root -> children[index] != NULL){
			child = root -> children[index];
		}else{
			return false;
		}

		return search(child, word.substr(1));
    }

public:
    bool search(string word){
    	return search(root, word);
    }

private:
	void removeWord(TrieNode* root, string word){
		if(word.size() == 0){
			root -> isTerminal = false;
			return;
		}

		int index = word[0] - 'a';
		TrieNode* child;

		if(root -> children[index] != NULL){
			child = root -> children[index];
		}else{
			return;	//word not found
		}

		removeWord(child, word.substr(1));

		//delete node if it is useless. ('a' in case of 'and') Assume rest is all deleted, hyptohesis.  
		if(child -> isTerminal == false){
			for(int i = 0; i < 26; i++){
				if(child -> children[i] != NULL){
					return;
				}
			}
			delete child;	//deletes node. 'a in case of 'and'
			root -> children[index] = NULL; 	//root is '\0' so we travel to root -> children[index of 'a' in case of 'and'] and mark it as NULL 		}
		}
	}

public:
	void removeWord(string word){
		removeWord(root, word);
	}
};