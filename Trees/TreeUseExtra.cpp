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