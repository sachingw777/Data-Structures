#include <iostream>
using namespace std;
#include "Fraction.cpp"

int main(){
    
    Fraction f1(10,3);
    Fraction f2(5,2);
    f1.print();

    f1+= f2;
    f1.print();
    f2.print();
  
  /*  Fraction f4 = ++(++f1);
    f1.print();
    f4.print();
*/

    // f1.multiply(f2);
    // f1.print();
    /*
    Fraction f3 = f1.add(f2);
    Fraction f4 = f1 * f2;

    f3.print();
    f4.print();

    if(f1 == f2){
        cout << "Equal";
    }else {
        cout << "Not Equal";
    }
    */
}