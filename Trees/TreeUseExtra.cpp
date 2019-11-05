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