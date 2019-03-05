// input1 - first array
// size1 - size of first array
// input2 - second array
// size2 - size of second array
// output - array in which sum is to be stored

void sumOfTwoArrays(int input1[], int size1, int input2[], int size2, int output[]){
    int size3;
    if(size1 > size2){size3= size1 +1;}
    else{size3 = size2 + 1;}
    
    int i = size1 - 1, j = size2 - 1, k = size3 - 1;
    int count = 0, carry = 0;
    
    while(count < size3){
        int psum = input1[i] + input2[j] + carry;
        int sum = psum % 10;
        carry = (sum > 9) ? psum/10 : 0;
        output[k] = sum;
        k--;
        
        if(i < 0 && j > 0){j--;}
        else if(j < 0 && i > 0){i--;}
        else if(i > 0 && j > 0){i--;j--;}
        
        if(i < 0 && j < 0){
            output[k] = carry;
            break;
        }
        count++; 
    }
}
