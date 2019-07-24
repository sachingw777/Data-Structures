int length1(char input[]){
  int len=0;
  for(int i = 0; input[i] != '\0'; i++){
    len++;
    }
  return len;
}


void removeAllOccurrencesOfChar(char input[], char c) {
  int i = 0, j = 0;
  int length = length1(input);
  while(i < length){
    if(input[i] != c){
		input[j] = input[i];
      j++;i++;
    }else{
      i++;
    }
  }
  input[j] = '\0';
}

/*
void removeAllOccurrencesOfChar(char input[], char c) {
    int j = 0;
    for(int i = 0; input[i] != '\0'; i++){
        if(input[i] != c){
            input[j] = input[i];
            j++;
        }
    }
    input[j] = '\0';
} */