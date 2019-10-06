#include <iostream>
#include "TreeNode.h"
#include <queue>
using namespace std;

TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout << "Enter Root:" << endl;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        cout << "Enter number of children of " << front -> data << endl;
        int numchild;
        cin >> numchild;

        for(int i = 0; i < numchild; i++){
            int childData;
            cout << "Enter" << i << "th child of " << rootData << endl;
            cin >> childData; 
            TreeNode<int>* child = new TreeNode<int>(childData);
            front -> children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

TreeNode<int>* takeInput(){
    int rootdata, n;
    cout << "Enter data" << endl;
    cin >> rootdata;
    TreeNode<int>* root = new TreeNode<int>(rootdata);
    cout << "Enter number of children of"<< rootdata << endl;
    cin >> n;

    for(int i = 0; i < n; i++){
        TreeNode<int>* child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

void printTreeLevelWise(TreeNode<int> * root){
     if(root == NULL){
        return;
    }   

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << front -> data << ":";
        for(int i = 0; i < front -> children.size(); i++){
            cout << front -> children[i] -> data;
            if(i != front -> children.size() -1 ){
                cout << ",";
            }
            pendingNodes.push(front -> children[i]);
        }
        cout << endl;
    }
}

void printTree(TreeNode<int> * root){
    if(root == NULL){
        return;
    }

    cout << root -> data << ":";
    for(int i = 0; i < root -> children.size(); i++){
        cout << root -> children[i] -> data << ",";
    }
    cout << endl;
    for(int i = 0; i < root -> children.size(); i++){
        printTree(root->children[i]);
    }
}
int countNodes(TreeNode<int>* root){
    int ans = 1;
    for(int i = 0; i < root -> children.size(); i++){
        ans += countNodes(root -> children[i]);
    }
    return ans;
}

int sumOfNodes(TreeNode<int>* root) {
    int sum = root -> data;
    for(int i = 0; i < root -> children.size(); i++){
        sum += sumOfNodes(root -> children[i]);
    }
    return sum;
}

TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    TreeNode<int> * max = root;
    for(int i = 0;i < root -> children.size(); i++){
        TreeNode<int>* temp = maxDataNode(root -> children[i]);
        if(temp -> data > max -> data){
            max = temp;
        }
    }
    return max;
}

int main(){
    /*
    TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>* node1 = new TreeNode<int>(2);
    TreeNode<int>* node2 = new TreeNode<int>(3);
    root -> children.push_back(node1);
    root -> children.push_back(node2);
    */
    TreeNode<int>* root = takeInputLevelWise();
    printTree(root);
};