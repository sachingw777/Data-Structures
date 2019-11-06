bool containsX(TreeNode<int>* root, int x) {
    if(root -> data == x){
        return true;
    }
    bool ans;
    for(int i = 0; i < root -> numChildren(); i++){
     ans = containsX(root -> getChild(i), x);
        if(ans == true){
            return true;
        }
    }
    return false;
}

int nodesGreaterThanX(TreeNode<int> *root, int x) {
    int count;
    if(root -> data > x){
        count = 1;
    }else{
        count = 0;
    } 
    for(int i = 0; i < root -> numChildren(); i++){
        count += nodesGreaterThanX(root -> getChild(i), x);
    }
    return count;
}

//another question
#include <climits>
template <typename T>
class MaxNodePair {
    TreeNode<T>* node;
    int sum;
};

//method 1 - TLE. need to fix it. 
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

//method 2. works.
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

// TLE.
TreeNode<int>* nextLargerElement(TreeNode<int> *root, int n) {
    if(root == NULL){
        return root;
    }
    
    TreeNode<int>* ans = NULL;
    if(root->data > n){
        ans = root;
    }
    
    for(int i = 0; i < root -> numChildren(); i++){
        TreeNode<int>* temp = nextLargerElement(root -> getChild(i), n);
        if(ans->data == NULL){
            ans = temp;
        }else if(temp != NULL && temp-> data < ans->data){
            ans = temp;
        }
    }
    return ans;
}