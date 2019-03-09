int sumOfDigits(int n) {
    if(n == 0){return 0;}
    // if(n <= 9){return n;}
    int sum =+ n%10;
    int small = sumOfDigits(n/10);
    return sum+small;
}
