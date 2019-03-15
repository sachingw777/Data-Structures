#include<iostream>
using namespace std;

void f(const int * p){
    (*p);
}
int main(){
    int i = 10;
    int j = 15;
    // int *p1 = &i;
    // f(p1);
    // cout << i;

    int * const p2 = &i;
    (*p2)++;
    cout << i;

    int const *p3 = &i;
    p3 = &j;
    (*p3)++;

}