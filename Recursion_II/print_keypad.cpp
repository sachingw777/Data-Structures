#include <string>
#include <iostream>
using namespace std;

void keypad(string input, string output){
    if(input.empty()){
        cout << output << endl;
        return;
    }


}

int main(){
    string input;
    cin >> input;
    string output = "";
    keypad(input, output);
}void printKeypad(int num){
    string output = "";
    printkeypad(num, output);
