#include <string>
using namespace std;

int returnPermutations(string input, string output[]){
    if(input.empty()){
        output[0] = "";
        return 1;
    }

    string smallOutput[1000];
    int small = returnPermutations(input.substr(1), smallOutput);

    int k = 0;
    for(int i = 0; i < small; i++){
        for(int j = 0; j <= smallOutput[i].length(); j++){
            output[k] = smallOutput[i].substr(0,j) + input[0] + smallOutput[i].substr(j);
            k++;
        }
    }
    return k;
}