#include <iostream>
#include "BinaryTreeNode.h"
#include "BinarySearchTree.h"
#include <vector>
#include <climits>
using namespace std;

vector<int>* findPath(BinaryTreeNode<int>* root , int data){
    if(root == NULL){
        return NULL;
    }

    if(root -> data == data){
    	vector<int>* output = new vector<int>();
    	output->push_back(root -> data);
    	return output;
    }

    vector<int>* leftOutput = findPath(root -> left, data);
    if(leftOutput != NULL){
    	leftOutput -> push_back(root->data);
    	return leftOutput;
    }

    vector<int>* rightOutput = findPath(root -> right, data);
    if(rightOutput != NULL){
    	rightOutput -> push_back(root->data);
    	return rightOutput;
    }else{
    	return NULL;
    }
}

template <typename T>
class Node{
    public:
    T data;
    Node<T> *next;
    
    Node(T data){
        this -> data = data;
        this -> next = NULL;
    }
};

class Pair{
    public:
    Node<int>* head;
    Node<int>* tail;
};

//BST to Sorted LL
Pair helper_constructBST(BinaryTreeNode<int>* root){
    if(root == NULL){
        Pair p;
        p.head = NULL;
        p.tail = NULL;
        return p;
    }

    Pair leftAns = helper_constructBST(root -> left);
    Pair rightAns = helper_constructBST(root -> right);
    
    Node<int>* rootNode = new Node<int>(root -> data);
    Pair output;
    if(leftAns.tail != NULL ){
    	leftAns.tail -> next = rootNode;
        output.head = leftAns.head;
    }else{
        output.head = rootNode;
    }

    if(rightAns.tail != NULL){
        rootNode -> next = rightAns.head;
    	output.tail = rightAns.tail;
    }else{
    	output.tail = rootNode;
    }

    return output;
}

Node<int>* constructBST(BinaryTreeNode<int>* root) {
    Pair out = helper_constructBST(root);
    return out.head;
}

//BST from array
BinaryTreeNode<int>* helper_constructTree(int *input, int startIndex, int endIndex){
    if(startIndex > endIndex){
        return NULL;
    }    
    
    int mid = (startIndex + endIndex)/2;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(input[mid]);
    root ->left = helper_constructTree(input, startIndex, mid - 1);
    root ->right = helper_constructTree(input, mid + 1, endIndex);
    return root;
}

BinaryTreeNode<int>* constructTree(int *input, int n) {
    return helper_constructTree(input, 0, n - 1);
}

bool isBST3(BinaryTreeNode<int>* root, int min = INT_MIN, int max = INT_MAX){
	if(root == NULL){
		return true;
	}
	if(root -> data < min || root -> data > max){
        return false;
    }
	bool isLeftOk = isBST3(root -> left, min, root -> data - 1);
	bool isRightOk = isBST3(root -> right, root -> data, max);

		return isLeftOk && isRightOk;
}

class isBSTReturn{
	public:
		int max;
		int min;
		bool isBST;
};

isBSTReturn isBST2(BinaryTreeNode<int>* root){
	if(root == NULL){
		isBSTReturn output;
		output.max = INT_MIN;
		output.min = INT_MAX;
		output.isBST = true;
		return output;
	}

	isBSTReturn leftOutput = isBST2(root -> left);
	isBSTReturn rightOutput = isBST2(root -> right);
	
	bool isBSTFinal = (root -> data > leftOutput.max) && (root -> data <= rightOutput.min) && rightOutput.isBST && leftOutput.isBST;
	isBSTReturn output;
	output.max = max(root -> data, max(leftOutput.max, rightOutput.max));
	output.min = min(root -> data, min(leftOutput.min, rightOutput.min));
	output.isBST = isBSTFinal;
	return output;
}

int maximum(BinaryTreeNode<int>* root){
	if(root == NULL){
		return INT_MIN;
	}

	return max(root -> data, max(maximum(root -> left), maximum(root -> right)));
}

int minimum(BinaryTreeNode<int>* root){
	if(root == NULL){
		return INT_MAX;
	}

	return min(root -> data, min(minimum(root -> left), minimum(root -> right)));
}

bool isBST(BinaryTreeNode<int>* root){
	if(root == NULL){
		return true;
	}

	int leftMax = maximum(root -> left);
	int rightMin = minimum(root -> right);

	bool output = (root -> data > leftMax) && (root -> data  <= rightMin) && isBST(root -> left) && isBST(root -> right);
	return output;
}

BinaryTreeNode<int>* searchInBST(BinaryTreeNode<int> *root , int k){
    if(root == NULL){
        return NULL;
    }
    
    if(root -> data == k){
        return root;
    }else if(root -> data > k){
        return searchInBST(root -> left, k);
    }else{
        return searchInBST(root -> right, k);
    }
}

int main(){

	// isBSTReturn output = isBST2(root);
	// cout << endl << "OUTPUT : ";
	// cout << output.isBST;
	// printTreeLevelWise(root);
	// delete root;
	BST b;
	b.insert(10);
	b.insert(5);
	b.insert(20);
	b.insert(7);
	b.insert(3);
	b.insert(15);
	b.printTree();
	b.deleteData(10);
	b.deleteData(100);
	b.printTree();

}