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
    //if(leftAns != NULL && rightAns == NULL){return leftAns;}else{return rightAns;}
    //if one of the 2 calls comes up with a null & other with node then return that node.
}

int lcaBinaryTree(BinaryTreeNode<int>* root , int val1, int val2){
	BinaryTreeNode<int>* ans = lca(root, val1, val2);
	if(ans != NULL){
		return ans -> data;
	}else{
		return -1;
	}
}

BinaryTreeNode<int>* lcaInBST_helper(BinaryTreeNode<int>* root , int val1 , int val2){
    if(root == NULL){
        return NULL;
    }
    if(root -> data == val1 || root -> data == val2){
        return root;
    }

    if(root -> data < val1 && root -> data < val2){
        return lcaInBST_helper(root -> right, val1, val2);
    }else if(root -> data > val1 && root -> data > val2){
        return lcaInBST_helper(root -> left, val1, val2);
    }else{
        BinaryTreeNode<int>* leftAns = lcaInBST_helper(root -> left, val1, val2);
        BinaryTreeNode<int>* rightAns = lcaInBST_helper(root -> right, val1, val2);

        if(leftAns != NULL && rightAns != NULL){
            return root;
        }

        if(leftAns == NULL && rightAns == NULL){
            return NULL;
        }

        return leftAns != NULL ? leftAns : rightAns;
    }

}

int lcaInBST(BinaryTreeNode<int>* root , int val1 , int val2){
    BinaryTreeNode<int>* ans = lcaInBST_helper(root, val1, val2);
    if(ans != NULL){
        return ans -> data;
    }else{
        return -1;
    }
}

int main() {
    // BinaryTreeNode<int>* root = takeInput();
    // insertDuplicateNode(root);
    // printLevelATNewLine(root);
    // delete root;
}