#include <string.h>
void helper(char input[], int index){
    int length = strlen(input);
    if(input[index] == '\0' || input[index + 1] == '\0'){
        return;
    }
    
    if(input[index] == input[index + 1]){
        input[length + 1] = '\0';
        for(int i = length - 1; i >= index; i--){
            input[i + 1] = input[i];
        }
        input[index + 1] = '*';
    }
    
    helper(input, index + 1);
}

void pairStar(char input[]) {
   
    helper(input, 0);   //Method 1

    int length = strlen(input); //Method 1.1
    if(length <= 1){
        return;
    }
    
    if(input[0] == input[1]){
        input[length + 1] = '\0';
        int i = length - 1;
        for(i; i >= 1; i--){
            input[i + 1] = input[i];
        }
        input[i + 1] = '*';
    }
    
    pairStar(input + 1);
}