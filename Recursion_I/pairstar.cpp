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
    // Write your code here
    helper(input, 0);
}
