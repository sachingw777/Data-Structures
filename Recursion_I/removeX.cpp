#include<cstring>
void qwerty(char S[], int start){
    if(S[start] == '\0'){
        return;
    }
    qwerty(S,start+1);
    
    if(S[start] == 'x'){
        int i = start + 1;
        for(i; i < strlen(S); i++){
            S[i-1] = S[i];
        }
        S[i-1] = '\0';
    }
    qwerty(S,start+1);
    
}
void removeX(char input[]) {
    // qwerty(input, 0);
    //Method 2
    int length = strlen(input);
    if(length == 0){
        return;
    }

    removeX(input + 1);

    if(input[0] == 'x'){
        for(int i = 0; i < length; i++){
            input[i] = input[i + 1];
        }   
    }
}
