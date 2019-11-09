#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
using namespace std;

void postOrder(BinaryTreeNode<int> *root) {
    if(root == NULL){
        return;
    }
    postOrder(root -> left);
    postOrder(root -> right);
    cout << root -> data << " ";
}


void preOrder(BinaryTreeNode<int> *root) {
    if(root == NULL){
        return;
    }  
    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);
}

void mirrorBinaryTree(BinaryTreeNode<int>* root) {
   	if(root == NULL){
   		return;
   	}

   	mirrorBinaryTree(root -> left);
   	mirrorBinaryTree(root -> right);

    BinaryTreeNode<int>* temp = root -> left;
    root -> left = root -> right;
    root -> right = temp;
}

int height(BinaryTreeNode<int> *root) {
    if(root == NULL){
        return 0;
    }

    int searchLeft = height(root -> left);
    int searchRight = height(root -> right);
    
    return max (searchLeft,searchRight) + 1;
}

bool isNodePresent(BinaryTreeNode<int>* root, int x) {
	if(root == NULL){
		return false;
	}

	if(root -> data == x){
		return true;
	}

	// return isNodePresent(root -> left, x) || isNodePresent(root -> right, x);
	bool searchLeft = isNodePresent(root -> left, x);
	bool searchRight = isNodePresent(root -> right, x);

	return searchLeft || searchRight;	
}

void inOrder(BinaryTreeNode<int>* root){
	if(root == NULL){
		return;
	}

	inOrder(root -> left);
	cout << root -> data << " ";
	inOrder(root -> right);
}

void printTreeLevelWise(BinaryTreeNode<int>* root){
	if(root == NULL){
		return;
	}
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	
	while(pendingNodes.size() != 0 ){
		BinaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();

		cout << front -> data << ":";
		cout << "L:"; 
		if(front -> left){
			cout << front -> left -> data << ",";	
			pendingNodes.push(front -> left);
		}else{
			cout << -1 << ",";	
		}

		cout << "R:"; 
		if(front -> right){
			cout << front -> right -> data << endl;	
			pendingNodes.push(front -> right);
		}else{
			cout << -1 << endl;	
		}
	}	
}

BinaryTreeNode<int>* takeInputLevelWise(){
	int rootData;
	cout << "Enter data" << endl;
	cin >> rootData;

	if (rootData == -1) {
		return NULL;
	}

	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);

	while(pendingNodes.size() != 0 ){
		BinaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();

		cout << "Enter left child of " << front -> data << " ";
		int leftChildData;
		cin >> leftChildData;
		if(leftChildData != -1){
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
			front -> left = child;
			pendingNodes.push(child);
		}

		cout << "Enter right child of " << front -> data << " ";
		int rightChildData;
		cin >> rightChildData;
		if(rightChildData != -1){
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
			front -> right = child;
			pendingNodes.push(child);
		}		
	}

	return root; 
}

void printTree(BinaryTreeNode<int>* root){
	if(root == NULL){
		return;
	}

	cout << root -> data << ":";
	if(root -> left != NULL){
		cout << "L"<< root -> left -> data;
	}
	if(root -> right != NULL){
		cout << "R"<< root -> right -> data;
	}
	cout << endl;
	printTree(root -> left);
	printTree(root -> right);
}

BinaryTreeNode<int>* takeInput( ){
	int rootData;
	cout << "Enter data" << endl;
	cin >> rootData;

	if(rootData == -1){
		return NULL;
	}

	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	BinaryTreeNode<int>* leftChild = takeInput();
	BinaryTreeNode<int>* rightChild = takeInput();

	root -> left = leftChild;
	root -> right = rightChild;

	return root;
}



/*
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
*/
int main(){
	// BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
	// BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
	// BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);

	// root -> left = node1;
	// root -> right = node2;

	// takeInput();
	BinaryTreeNode<int>*root =  takeInputLevelWise();
	// takeInput();
	printTreeLevelWise(root);
	// inOrder(root);
	mirror(root);
	printTreeLevelWise(root);
	delete root;
}