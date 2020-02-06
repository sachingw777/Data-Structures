#include <iostream>
#include "BinaryTreeNode.h"
#include "BinarySearchTree.h"
using namespace std;

void insertDuplicateNode(BinaryTreeNode<int> *root) {
    if(root == NULL){
        return;
    }
    
    insertDuplicateNode(root -> left);
    insertDuplicateNode(root -> right);
    
    BinaryTreeNode<int>* temp = root -> left;
    BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(root -> data);
    root -> left = newNode;
    newNode -> left = temp;
}

BinaryTreeNode<int>* lca(BinaryTreeNode<int>* root , int val1, int val2){
	if(root == NULL){
		return root;
	}

	if(root -> data == val1 || root -> data == val2){
		return root;
	}

	BinaryTreeNode<int>* leftAns = lca(root -> left, val1, val2);
	BinaryTreeNode<int>* rightAns = lca(root -> right, val1, val2);

	if(leftAns != NULL && rightAns != NULL){
		return root;
	}

	if(leftAns == NULL && rightAns == NULL){
		return NULL;
	}

    return leftAns != NULL ? leftAns : rightAns;
}

int lcaBinaryTree(BinaryTreeNode<int>* root , int val1, int val2){
	BinaryTreeNode<int>* ans = lca(root, val1, val2);
	return ans -> data;
}

int main() {
    // BinaryTreeNode<int>* root = takeInput();
    // insertDuplicateNode(root);
    // printLevelATNewLine(root);
    // delete root;
}