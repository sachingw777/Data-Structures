#include<string.h>

int findString(char S[], char T[]){
    int length1 = strlen(S);    
    int length2 = strlen(T);
    
    for(int i = 0; i <= length1 - length2; i++){
        int j = 0;
        while(j < length2 && (S[i + j] == T[j])){
            j++;
        }
        if(j == length2){
            return i;
        }
    }
    return -1;
}