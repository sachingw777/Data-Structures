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

int main() {
    BinaryTreeNode<int>* root = takeInput();
    insertDuplicateNode(root);
    printLevelATNewLine(root);
    delete root;
}