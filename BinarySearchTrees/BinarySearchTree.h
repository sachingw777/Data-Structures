#include "BinaryTreeNode.h"
using namespace std;

class BST(){
	BinaryTreeNode<int>* root;

public:
	BST(){
		root = NULL;
	}

	~BST(){
		delete root;
	}

private:
	bool hasData(int data, BinaryTreeNode<int>* node){
	if(node == NULL){
		return false;
	}

	if(node -> data == data){
		return true;
	}

	return hasData(data, node -> left) || hasData(data, node -> right);
}

public:
	bool hasData(int data){
		return hasData(data, root);
	}

};