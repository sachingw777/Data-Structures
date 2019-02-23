#include<iostream>
using namespace std;

int main(){
    int a[] = {1,2,3,4};
    char b[] = "abc";

    cout << a << " " << b << endl;

    char c = 'a';
    char c1[] = "bat";

    char *pc = &c;
    char *pc1 = c1;
    
    cout << c << " " << pc << " " << pc1<< endl;
    cout << sizeof(c) << " " << sizeof(c1) << " " << sizeof(pc) << endl;

    char str[] = "abcde";
    char *pstr = "abcde";
}