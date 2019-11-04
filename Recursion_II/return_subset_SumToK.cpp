/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 3, 4, 2} and K = 5, then output array should contain
	{{2, 1, 4},	// Length of this subset is 2
	{2, 3, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/
int helper(int input[], int n, int startIndex, int output[][50], int k){
	if(startIndex == n){
		if(k == 0){
			output[0][0] = 0;
			return 1;
		}
		else{
			return 0;
		}
	}

	int output_2[1000][50], output_1[1000][50];

	int s1 = helper(input, n, startIndex + 1, output_1, k);
	int s2 = helper(input, n, startIndex + 1, output_2, k - input[startIndex]);

	int s0 = 0; //output row
	for(int i = 0; i < s1; i++){
		for (int j = 0; j <= output_1[i][0]; j++){
			output[s0][j] = output_1[i][j];			
		}
		s0++;
	}

	for(int i = 0; i < s2; i++){
		output[s0][0] = output_2[i][0] + 1;
		output[s0][1] = input[startIndex];
		for(int j = 1; j <= output_2[i][0]; j++){
			output[s0][j + 1] = output_2[i][j];
		}
		s0++;
	}
	return s0;
}

int subsetSumToK(int input[], int n, int output[][50], int k) {
	return helper(input, n, 0, output, k);
}