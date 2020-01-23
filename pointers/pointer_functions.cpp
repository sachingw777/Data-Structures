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
    int j = 20;
    int *p = &i;

    const int * p2 = &i;
    p2 = &j;
    (*p2)++;

    cout << p << endl;
    cout << *p2 << endl;
    // increment(p);
    // cout << p << endl; 
    // cout << *(p);


}