class Fraction{
    private:
        int numerator;
        int denominator;

    public:

        Fraction(int numerator, int denominator){
            this -> numerator = numerator;
            this -> denominator = denominator;
        }

        void print(){
            cout << numerator << " / " << denominator << endl;
        }

        void simplify(){
            int gcd = 1;
            int j = min(this->numerator, this->denominator);
            for(int i = 1; i <= j; i++){
                if(this->numerator % i == 0 && this->denominator % i == 0){
                    gcd = i;
                }
            }
            this->numerator /= gcd;
            this->denominator /= gcd;
        }

        void add(Fraction const & f2){
            denominator = this->denominator * f2.denominator;
            numerator = (this->numerator * f2.denominator) + (f2.numerator * this->denominator);
            simplify();
        }

        void multiply(Fraction const & f2){
            numerator = numerator * f2.numerator;
            denominator = denominator * f2.denominator;
            simplify();
        }

};