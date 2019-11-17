#include <climits>
template <typename T>
class MaxNodePair {
	TreeNode<T>* node;
	int sum;
};

MaxNodePair<int>*  maxSumNode_helper(TreeNode<int>* root){
	if(root == NULL){
		MaxNodePair<int>* pair = new MaxNodePair<int>();
		pair -> node = NULL;
		pair -> sum = INT_MIN;
	}

	int sum = root -> data;
	for(int i = 0; i < root -> numChildren(); i++){
		sum += root -> getChild(i) -> data;
	}

	MaxNodePair<int>* ans = new MaxNodePair<int>();
	for(int i = 0; i < root -> numChildren(); i++){
		MaxNodePair<int>* childAns = maxSumNode_helper(root->getChild(i));
		if(childAns-> sum > ans -> sum){
			ans = childAns;
		}
	}
	return ans;
}

void maxSumNode_helper2(TreeNode<int>* root, TreeNode<int>** resNode, int* max){
	if(root == NULL){
		return;
	}

	int sum = root -> data;

	for(int i = 0; i < root -> numChildren(); i++){
		sum += root -> getChild(i) -> data;
		maxSumNode_helper2(root->getChild(i), resNode, max);
	}
	if(sum > *max){
		*resNode = root;
		*max = sum;
	}
	return;
}

TreeNode<int>* maxSumNode(TreeNode<int> *root){
	TreeNode<int>* resNode;
	int maxSum = 0;
	// return maxSumNode_helper(root, &resNode, &maxSum);
	maxSumNode_helper2(root, &resNode, &maxSum);
	return resNode;
}