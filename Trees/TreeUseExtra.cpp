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

#include <climits>
template<typename T>
class Pair{
    public:
        TreeNode<int>* node;
        int sum;
};

Pair<int>* maxSumNodeHelper(TreeNode<int>* root){
    if(root == NULL){
        Pair<int> * p = new Pair<int>();
        p->node = NULL;
        p->sum = INT_MIN;
        return p;
    }

    Pair<int> *ans = new Pair<int>();
    ans->node = root;
    int sum = root -> data;
    for(int i = 0; i < root -> numChildren(); i++){
        sum += root->getChild(i)->data;
    }
    ans->sum = sum;

    for (int i = 0; i < root -> numChildren(); i++)
    {
        Pair<int> *childAns = maxSumNodeHelper(root -> getChild(i));
        if(childAns -> sum > ans -> sum){
            ans = childAns;
        }
    }
    return ans;
}

//method 2. works.
// void maxSumNode_helper2(TreeNode<int>* root, TreeNode<int>** resNode, int* max){
//     if(root == NULL){
//         return;
//     }

//     int sum = root -> data;

//     for(int i = 0; i < root -> numChildren(); i++){
//         sum += root -> getChild(i) -> data;
//         maxSumNode_helper2(root->getChild(i), resNode, max);
//     }
//     if(sum > *max){
//         *resNode = root;
//         *max = sum;
//     }
//     return;
// }

TreeNode<int>* maxSumNode(TreeNode<int> *root){
    Pair<int> *ans = maxSumNodeHelper(root);
    return ans -> node;

//     TreeNode<int>* resNode;
//     int maxSum = 0;
//     // return maxSumNode_helper(root, &resNode, &maxSum);
//     maxSumNode_helper2(root, &resNode, &maxSum);
//     return resNode;
//
}



//Method 3.
// TreeNode<int>* maxSumNode3(TreeNode<int> *root){
//     TreeNode<int>* max = root;
//     int sum = root->data;
//     for(int i = 0; i < root -> numChildren(); i++){
//         sum += root->getChild[i]->data;
//         TreeNode<int>* temp = maxSumNode3(root->getChild[i])
//             if(temp -> data > sum->data){
//         temp = sum;
//         }
//     }
// }

TreeNode<int>* nextLargerElement(TreeNode<int> *root, int n) {
    if(root == NULL){
        return root;
    }
    TreeNode<int> * ans;
    if(root->data > n){
        ans = root;
    }else{
        ans = NULL;
    }
    
    for(int i = 0; i < root -> numChildren(); i++){
        TreeNode<int>* temp = nextLargerElement(root -> getChild(i), n);
        
        if(ans == NULL && temp != NULL){
            ans = temp;
        }

        if(temp != NULL && temp-> data < ans->data){
            ans = temp;
        }
    }
    return ans;
}

void replaceWithDepthValue_helper(TreeNode<int> *root, int depth){
    if(root == NULL){
        return;
    }
    root->data = depth;
    for(int i = 0; i < root->numChildren(); i++){
        replaceWithDepthValue_helper(root->getChild(i), depth + 1);
    }

}

void replaceWithDepthValue(TreeNode<int> *root){    
    replaceWithDepthValue_helper(root, 0);
}
int numLeafNodes(TreeNode<int>* root) {
    int count = 0;
    if(root->numChildren() == 0){
        count += 1;
    }

    for(int i = 0; i < root->numChildren(); i++){
        count += numLeafNodes(root->getChild(i));
    }
    return count;
}

bool isIdentical(TreeNode<int>* root1, TreeNode<int>* root2){
    if(root1 == NULL && root2 == NULL){
        return false;
    }

    if((root1 != NULL && root2 == NULL) || (root1 == NULL && root2 != NULL)){
        return false;
    }

    if((root1 -> data != root2->data) || (root1->numChildren() != root2->numChildren())){
        return false;
    }
    int i = 0;
    while(i < root1->numChildren()){
        TreeNode<int>* child1 = root1->getChild(i);
        TreeNode<int>* child2 = root2->getChild(i);

        if(isIdentical(child1, child2)){
            i++;
        }
        else{
            return false;
        }
    }
    return true;
}