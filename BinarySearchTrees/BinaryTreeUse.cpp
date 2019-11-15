#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
#include<climits>
using namespace std;

bool isBST3(BinaryTreeNode<int>* root, int min = INT_MAX, int max = INT_MIN){
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
		return INT_MIN;
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


void nodesWithoutSibling(BinaryTreeNode<int> *root) {
    if(root == NULL){
        return;
    }
    
    if(root -> left == NULL && root -> right != NULL){
        cout << root -> right -> data << endl;
    }    if(root -> left != NULL && root -> right == NULL){
        cout << root -> left -> data << endl;
    }
    nodesWithoutSibling(root -> right);
    nodesWithoutSibling(root ->left);
}

BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) {
	if(root == NULL){
		return NULL;
	}

	if(root -> left == NULL && root -> right == NULL){
		return NULL;
	}

	root -> left = removeLeafNodes(root -> left);
	root -> right = removeLeafNodes(root -> right);
	return root;
}

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    if(root == NULL){
        return;
    }
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
    	BinaryTreeNode<int>* front = q.front();
    	q.pop();
    	if(front == NULL){
    		if(q.empty()){
    			break;
    		}
    		cout << endl;
    		q.push(NULL);
    		continue;
    	}
    	cout << front -> data << " ";
    	if(front -> left != NULL){
    		q.push(front -> left);
    	}    	
    	if(front -> right != NULL){
    		q.push(front -> right);
    	}
    }
}

pair<bool,int> helper_isbalanced(BinaryTreeNode<int>* root){
	if(root == NULL){
		pair<bool,int> p;
		p.first = true;
		p.second = 0;
		return p;
	}

	pair<bool,int> leftAns = helper_isbalanced(root -> left);
	pair<bool,int> rightAns = helper_isbalanced(root -> right);

    bool flag;
	if((leftAns.first && rightAns.first == true) && (abs(leftAns.second - rightAns.second)) <= 1){
		flag = true;
	}else{
		flag = false;
	}
	
	pair<bool,int> p;
	p.first = flag;
	p.second = max(leftAns.second, rightAns.second) + 1;
	return p;
}

bool isBalanced_optimized(BinaryTreeNode<int> *root) { 
    if(root == NULL){
        return true;
    }
	
	pair<bool,int> p = helper_isbalanced(root);
	return p.first;
}

bool isBalanced(BinaryTreeNode<int> *root) { 
//O(nlogn)
    if(root == NULL){
        return true;
    }

    int rightHeight = height(root -> right);
    int leftHeight = height(root -> left);
    
    if(abs(rightHeight - leftHeight) <= 1){
    	bool leftAns = isBalanced(root -> left);
    	bool rightAns = isBalanced(root -> right);

    	return leftAns && rightAns;
    }else{
    	return false;
    }
}

 // PairAns class -
class PairAns {
    public :
        int min;
        int max;
};

PairAns minMax(BinaryTreeNode<int> *root) {
    if(root == NULL){
    	PairAns p;
    	p.min = INT_MAX;
    	p.max = INT_MIN;
    	return p;
    }

    PairAns leftAns = minMax(root -> left);
    PairAns rightAns = minMax(root -> right);

   	PairAns ans;
    ans.max = max(max(leftAns.max, rightAns.max), root -> data);
    ans.min = min(min(leftAns.min, rightAns.min), root -> data);
    return ans;
}

pair<int,int> heightDiameter(BinaryTreeNode<int>* root){
	if(root == NULL){
		pair<int,int> p;
		p.first = 0;
		p.second = 0;
		return p;
	}

	pair<int,int> leftAns = heightDiameter(root -> left);
	pair<int,int> rightAns = heightDiameter(root -> right);

	int left_height = leftAns.first;
	int right_height = rightAns.first;
	int left_diameter =leftAns.second;
	int right_diameter =rightAns.second;

	int height = 1 + max(left_height, right_height);
	int diameter = max(left_height + right_height, max(left_diameter, right_diameter));
	pair<int,int> p;
	p.first = height;
	p.second = diameter;
	return p;
}

int heightfordiameter(BinaryTreeNode<int>* root){
	if(root == NULL){
		return 0;
	}
	return 1 + max(heightfordiameter(root -> left), heightfordiameter(root -> right));
}

int diameter(BinaryTreeNode<int>* root){
	if(root == NULL){
		return 0;
	}

	int option1 = heightfordiameter(root -> left) + heightfordiameter(root -> right);
	int option2 = diameter(root -> left);
	int option3 = diameter(root -> right);

	return max(option1, max(option2, option3));
}

BinaryTreeNode<int>* helper_getTreeFromPostorderAndInorder(int *postorder, int postorderStart, int postorderEnd, int *inorder, int inorderStart, int inorderEnd){
	if(inorderStart > inorderEnd){
		return NULL;
	}

	int rootData = postorder[postorderEnd];
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	int rootIndex_post = postorderEnd;
	int rootIndex_inorder;

	for(int i = inorderStart; i <= inorderEnd; i++){
		if(inorder[i] == rootData){
			rootIndex_inorder = i;
			break;
		}
	}

	int left_inorderStart = inorderStart;
	int left_inorderEnd = rootIndex_inorder - 1;
	int right_inorderStart = rootIndex_inorder + 1;
	int right_inorderEnd = inorderEnd;
	
	int left_postorderStart = postorderStart;
    int left_postorderEnd =  left_inorderEnd - left_inorderStart + left_postorderStart;
	int right_postorderEnd = rootIndex_post - 1;
	int right_postorderStart = left_postorderEnd + 1;

	root -> left = helper_getTreeFromPostorderAndInorder(postorder, left_postorderStart, left_postorderEnd, inorder, left_inorderStart, left_inorderEnd);
	root -> right = helper_getTreeFromPostorderAndInorder(postorder, right_postorderStart, right_postorderEnd, inorder, right_inorderStart, right_inorderEnd);
	return root;
}

BinaryTreeNode<int>* getTreeFromPostorderAndInorder(int *postorder, int postLength, int *inorder, int inLength) {
    return helper_getTreeFromPostorderAndInorder(postorder, 0, postLength - 1, inorder, 0, inLength - 1);
}

BinaryTreeNode<int>* buildTreeHelper(int *preorder, int preorderStart, int preorderEnd, int *inorder, int inorderStart, int inorderEnd) {
    if(inorderStart > inorderEnd){
        return NULL;
    }
	int rootData = preorder[preorderStart];
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	int rootIndex;
	for(int i = inorderStart; i <= inorderEnd; i++){
		if(inorder[i] == rootData){
			rootIndex = i;
			break;
		}
	}
	int left_inorderStart = inorderStart;
	int left_inorderEnd = rootIndex - 1;
	int left_preorderStart = preorderStart + 1;
	int left_preorderEnd =  left_inorderEnd - left_inorderStart + left_preorderStart;
	int right_preorderEnd = preorderEnd;
	int right_preorderStart = left_preorderEnd + 1;
	int right_inorderStart = rootIndex + 1;
	int right_inorderEnd = inorderEnd;

	root -> left = buildTreeHelper(preorder, left_preorderStart, left_preorderEnd, inorder, left_inorderStart, left_inorderEnd);
	root -> right = buildTreeHelper(preorder, right_preorderStart, right_preorderEnd, inorder, right_inorderStart, right_inorderEnd);
	return root;
}

BinaryTreeNode<int>* buildTree(int *preorder, int preLenght, int *inorder, int inLength) {
	return buildTreeHelper(preorder, 0, preLenght - 1, inorder, 0, inLength - 1);
}

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
	// printTreeLevelWise(root);
	// inOrder(root);
	// mirror(root);
	printTreeLevelWise(root);
	// buildTreeHelper();
	// diameter(root);
	cout << endl;
	pair<int,int> p = heightDiameter(root);
	cout << "Height:- " << p.first;
	cout << "Diameter:- " << p.second;
	delete root;
}