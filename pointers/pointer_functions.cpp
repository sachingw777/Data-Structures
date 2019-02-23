#include<iostream>
using namespace std;

void incrementPointer(int * p){
    p++;
}

void increment(int * p){
    (*p)++;
}


int main(){
    int i = 10;
    int *p = &i;
    cout << p << endl;
    increment(p);
    // cout << p << endl; 
    cout << *(p);
}