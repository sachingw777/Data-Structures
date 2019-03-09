
int countZeros(int n) {
    // Write your code here
     int count = 0;

  if(n == 0){
    return 1;
  }                  // stop case zeroCount(0)
  if(n < 9){
    return 0;  // stop case digit between 1..9 or -9..-1
  }
  
  if (n % 10 == 0){ // if the num last digit is zero
       count++; // count the zero, take num last digit out
  }
    
   return count + countZeros(n/10);

}