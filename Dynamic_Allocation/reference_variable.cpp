#include<iostream>
using namespace std;

int main(){
    int i = 10;
    int& j = i;
    int k = 100;
    j=k;
    cout << &j << " " << &i <<endl;
    cout << sizeof(j) << " " << sizeof(i);

} 
