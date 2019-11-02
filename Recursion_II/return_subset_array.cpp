/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 2}, then output should contain 
	{{0}, 		// Length of this subset is 0
	{1, 2},		// Length of this subset is 1
	{1, 1},		// Length of this subset is also 1
	{2, 1, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/

int sub(int input[], int startIndex, int n, int output[][20]){
	if(startIndex == n){
		output[0][0] = 0;
		return 1;
	}

	int outputSize = sub(input, startIndex + 1, n, output);

	for(int i = 0; i < outputSize; i++){
		output[i + outputSize][0] += output[i][0] + 1;
		output[i + outputSize][1] = input[startIndex];

		for(int j = 1; j <= output[i][0]; j++){
			output[i + outputSize][j + 1] = output[i][j]; 
		}  
	}
	return 2 * outputSize;
}

int subset(int input[], int n, int output[][20]) {
    return sub(input, 0, n, output);
}