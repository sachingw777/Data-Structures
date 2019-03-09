#include <cstring>
bool helper(char S[], int start, int end){
    int length = strlen(S);
    if(length == 0 || length == 1){    //base case
        return true;
    }
    
    if(start >= end){
        return true;
    }
    
    if(S[start] == S[end]){    //small calc
        return helper(S, start + 1, end - 1);
    }else{
        return false;
    }
    
}

bool checkPalindrome(char input[]) {
    int length = strlen(input);
    helper(input,0,length-1);
}