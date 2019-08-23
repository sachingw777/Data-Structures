#include <string.h>
#include<bits/stdc++.h> 

//Method 1
int qwerty(char input[], int length){

    if(length == 0){
        return input[length] - '0';
    }
    
    int small = input[length] - '0';
    return (qwerty(input, length - 1) * 10) + small;
}

int stringToNumber(char input[]) {
    
    return qwerty(input,strlen(input) - 1);
}


