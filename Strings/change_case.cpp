void convertStringToLowerCase(char input[]) {
//abcde - ABCDE
//ABCDE - abcde
	int i = 0;
	while(input[i] != '\0'){
		if(input[i] >= 'A' & input[i] <='Z'){
			input[i] = input[i] + 32;
		}
		i++;	
	}
}