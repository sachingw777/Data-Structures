#include<iostream>
using namespace std;

int main(){
    int a[100] = {1,2,3,4};
    cout << "Array address:" << a << endl;

    int *p = a;
    cout << p << endl;
    cout << "Size of p:" << sizeof(p) << endl;
    
    double a2 = 12.1;
    double *dp = &a2;
    cout << "Size of dp:" << sizeof(dp) << endl;

    cout <<"****************" << endl;

    
} 