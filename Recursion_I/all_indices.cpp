
int allIndexes(int input[], int size, int x, int output[]) {
   if(size == 0){
        return 0;
    }

    int smallAns = allIndexes(input + 1, size - 1, x, output);
    
    if(input[0] == x){
        for(int i = smallAns - 1; i >= 0; i--){
            output[i + 1] = output[i] + 1;
        }
        output[0] = 0;
        smallAns++;
    }else{
        for(int i = 0; i < smallAns; i++){
            output[i]++;
        }
    }
    return smallAns;
}