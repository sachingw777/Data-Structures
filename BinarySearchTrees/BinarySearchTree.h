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
	BinaryTreeNode<int>* deleteData(int data, BinaryTreeNode<int>* node){
		if(node == NULL){
			return NULL;
		}

		if(data > node -> data){
			node -> right = deleteData(data, node -> right);
			return node;
		}else if( data < node -> data){
			node -> left = deleteData(data, node -> left);
			return node;
		}else{
			if(node -> left == NULL && node -> right == NULL){	//NO CHILD
				delete node;
				return NULL;
			}else if(node -> right != NULL && node -> left == NULL){
				BinaryTreeNode<int>* temp = node -> right;
				node -> right = NULL;
				delete node;
				return temp;
			}else if(node -> left != NULL && node -> right == NULL){
				BinaryTreeNode<int>* temp = node -> left;
				node -> left = NULL;
				delete node;
				return temp;
			}else{
				//find min of right side
				BinaryTreeNode<int>* temp = node -> right;
				while(temp -> left != NULL){
					temp = temp -> left;
				}
				node -> data = temp -> data;
				node -> right = deleteData(temp -> data, node -> right);
				return node;
			}
		}
	}

public:
	void deleteData(int data){
		this -> root = deleteData(data, this -> root);
	}

private:
	BinaryTreeNode<int>* insert(int data, BinaryTreeNode<int>* node){
		if(node == NULL){
			BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
			return newNode;
		}

		if(node -> data > data){
			node -> right = insert(data,node -> right);
		}else{
			node -> left = insert(data, node -> left);
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