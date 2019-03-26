#include <string>
using namespace std;

int keypad(int num, string output[]){
    if(num == 0){
        output[0] = "";
        return 1;
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
    

    
    int smallNumber = num / 10;
    int last = num % 10;
    string smallOutput[1000];
    int count = keypad(smallNumber, smallOutput);
    int j = 0, i = 0,k = 0;
    while(j < keyarr[last].size()){
        i = 0;
        while(i < count){
            output[k] = smallOutput[i] + keyarr[last].substr(j,1);
            i++;
            k++;
        }
        j++;
    }
    return k;
}