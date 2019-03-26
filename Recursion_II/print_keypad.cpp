#include <iostream>
#include <string>
using namespace std;

void printkeypad(int num, string output){
    if(num == 0){
        cout << output << endl;
        return;
    }
    
    string keyarr[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz",
    };
    
    int last = num%10;
    int smallNum = num / 10;
    
    for(int i = 0; i < keyarr[last].size(); i++){
        printkeypad(smallNum, keyarr[last].substr(i,1) + output);
    }
    
}

int main(){
    int input;
    cin >> input;
    string output = "";
    printkeypad(input, output);
}