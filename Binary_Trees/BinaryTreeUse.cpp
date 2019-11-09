#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
using namespace std;

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
		cout << "L"<< root -> right -> data;
	}
	cout << endl;
	printTree(root -> left);
	printTree(root -> right);
}

BinaryTreeNode<int>* takeInput(BinaryTreeNode<int>* root){
	int rootData;
	cout << "Enter data" << endl;
	cin >> rootData;

	if(rootData == -1){
		retunr NULL;
	}

	BinaryTreeNode<int>* root = new BinaryTreeNode<int>*(rootData);
	BinaryTreeNode<int>* leftChild = takeInput();
	BinaryTreeNode<int>* rightChild = takeInput();

	root -> left = leftChild;
	root -> right = rightChild;
}

int main(){
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
	BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
	BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);

	root -> left = node1;
	root -> right = node2;
}