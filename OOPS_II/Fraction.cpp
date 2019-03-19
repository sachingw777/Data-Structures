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

        Fraction add(Fraction const &f2){
            int den = this->denominator * f2.denominator;
            int num = (this->numerator * f2.denominator) + (f2.numerator * this->denominator);
            Fraction fNew(num, den);
            fNew.simplify();
            return fNew;
        }

        Fraction operator+(Fraction const &f2){
            int den = this->denominator * f2.denominator;
            int num = (this->numerator * f2.denominator) + (f2.numerator * this->denominator);
            Fraction fNew(num, den);
            fNew.simplify();
            return fNew;
        }

        Fraction operator*(Fraction const & f2){
            int num = this->numerator * f2.numerator;
            int den = this->denominator * f2.denominator;
            Fraction fNew(num,den);
            fNew.simplify();
            return fNew;
        }

        bool operator==(Fraction const &f2){
            return (this->numerator == f2.numerator && this->denominator == f2.denominator); 
        }

        //Pre-Increment Operator
        Fraction& operator++(){
            numerator = numerator + denominator;
            simplify();

            return *this;
        }

        //Post-Increment Operator
        Fraction operator++(int){
            Fraction fNew(numerator, denominator);
            numerator = numerator + denominator;
            simplify();
            fNew.simplify();
            return fNew;

        }
        
        Fraction operator+=(Fraction const &f2){
            int den = this->denominator * f2.denominator;
            int num = (this->numerator * f2.denominator) + (f2.numerator * this->denominator);
            Fraction fNew(num, den);
            fNew.simplify();
            return fNew;
}
        void multiply(Fraction const & f2){
            numerator = numerator * f2.numerator;
            denominator = denominator * f2.denominator;
            simplify();
        }
        int getNumerator()const{
            return numerator;
        }

        int getDenominator()const{
            return denominator;
        }
};