#include <cstring>
void qwerty(char S[], int start){
    int length = strlen(S);
    
    if(S[start] == '\0' || S[start + 1] == '\0'){
        return;
    }

    if(S[start] == 'p' && S[start + 1] =='i'){
        S[length + 2] = '\0';
        
        for(int i= length - 1; i > start + 1; i--){
            S[i+2] = S[i];
        }
          S[start] = '3';
          S[start + 1] = '.';
          S[start + 2] = '1';
          S[start + 3] = '4';
    }

    qwerty(S, start + 1);
   
}

void replacePi(char input[]) {
    qwerty(input,0);

    //Method 2
       int length = strlen(input);

    if(length <= 1){
        return;
    }
    
    if(input[0] == 'p' && input[1] == 'i'){
        input[length + 2] = '\0';
        for(int i = length - 1; i > 1; i--){
            input[i + 2] = input[i];
        }
        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';
    }   
     replacePi(input + 1);
}