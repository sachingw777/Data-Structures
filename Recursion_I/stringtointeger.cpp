#include <string.h>
#include<bits/stdc++.h> 

//Method 1
int qwerty(char input[], int index){

    if(index == 0){
        return input[index] - '0';
    }
    
    int small = input[index] - '0';
    return (qwerty(input, index - 1) * 10) + small;
}

int stringToNumber(char input[]) {
    
    return qwerty(input,strlen(input) - 1);
}


