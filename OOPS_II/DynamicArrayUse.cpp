#include <iostream>
using namespace std;
#include "DynamicArray.cpp"

int main(){
    DynamicArray d1;
    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);
    
    d1.print();
    d1.add(12,131);
    
    d1.print();

    DynamicArray d2(d1);
    // d2 = d1;
    d2.print(); 
}
