void SubsetHelper(int input[], int size, int startIndex, int output[], int outputSize){
	if(startIndex == size){
		for(int i = 0; i < outputSize; i++){
			cout << output[i] << " ";
		}
		cout << endl;
		return;
	}

	int smallOutput[50], smallSize = 0;
	SubsetHelper(input, size, startIndex + 1, output, outputSize);

	int i;
	for (i = 0; i < outputSize; i++)
	{
		smallOutput[i] = output[i];
	}
	smallOutput[i] = input[startIndex];
	SubsetHelper(input, size, startIndex + 1, smallOutput, outputSize + 1);
}

void printSubsetsOfArray(int input[], int size) {
	int output[1000];
	return SubsetHelper(input, size, 0 , output, 0);      
}