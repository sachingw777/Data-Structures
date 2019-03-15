#include <math.h>

class ComplexNumbers {
    // Complete this class
    private:
    
    int real;
    int imaginary;
    
    public:
    
    ComplexNumbers(int real, int imaginary){
        this->real = real;
        this->imaginary = imaginary;
    }
    
    void plus(ComplexNumbers const & C2){
        this->real += C2.real;
        this->imaginary += C2.imaginary;
    }
    
    void multiply(ComplexNumbers C2){
        int real = (this -> real * C2.real) - (this -> imaginary * C2.imaginary); 
        int imaginary = (this -> real * C2.imaginary) + (this -> imaginary * C2.real);
        this->real =  real;
        this->imaginary = imaginary;
    }
    
    void print(){
        cout << real << " + " << "i" << imaginary << endl; 
    }
};