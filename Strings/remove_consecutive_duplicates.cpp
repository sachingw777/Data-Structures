int length1(char input[]){
  int len=0;
  for(int i = 0; input[i] != '\0'; i++){
    len++;
    }
  return len;
}

void removeConsecutiveDuplicates(char input[]) {
  int i = 0, j = 0;
  int length = length1(input);
  while(j < length){
	if(input[i] != input[j]){
		input[j + 1] = input[i];
	j++;
	}else{
	i++;
	}
	}
	input[++j] = '\0';
}