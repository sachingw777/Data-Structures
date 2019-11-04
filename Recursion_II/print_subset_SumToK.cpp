void helper(int input[], int size, int startIndex, int k, int output[], int output_size){
    if(startIndex == size){
        if(k == 0){
            for(int i = 0; i < output_size; i++){
                cout << output[i] << " ";
            }
            cout << endl;
        }
        return;
    }

    int smallOutput[1000], smallOutput_size = 0;
    helper(input, size, startIndex + 1, k, output, output_size);

    int i;
    for(i = 0; i < output_size; i++){
        smallOutput[i] = output[i];
    }
    smallOutput[i] = input[startIndex];
    helper(input, size, startIndex + 1, k - input[startIndex], smallOutput, output_size + 1);
}

void printSubsetSumToK(int input[], int size, int k) {
    int output[1000];
    helper(input, size, 0, k, output, 0);
}