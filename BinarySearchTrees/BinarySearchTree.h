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
	BinaryTreeNode delete(int data, BinaryTreeNode<int>* node){
		if(root == NULL){
			return NULL;
		}

		
	}

public:
	void deleteData(int data){

	}

	void printTree(){
		
	}
private:
	BinaryTreeNode<int>* insert(int data, BinaryTreeNode<int>* node){
		if(node == NULL){
			BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
			return newNode;
		}

		if(node -> data > data){
			node -> right = insert(node -> right, data);
		}else{
			node -> left = insert(node -> left, data);
		}

		return node;
}
public:
	void insert(int data){
		this -> root = insert(data, this -> root);		
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