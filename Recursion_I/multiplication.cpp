int multiplyNumbers(int m, int n) {

  if(n==1){
    return m;
}
  int smallAns =multiplyNumbers(m, n-1);
  return m +smallAns;

}

