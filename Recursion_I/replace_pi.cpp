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
}