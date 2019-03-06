#include <string.h>
void reverse(char input[], int i, int j){
	while(i < j){
		char temp = input[i];
		input[i] = input[j];
		input[j] = temp;
      i++;
      j--;
	}
}

void reverseEachWord(char input[]) {
	int start = 0, end = 0, index = 0;
	while(input[index] != '\0' ){
		if(input[index] == ' '){
			end = index - 1;
			reverse(input,start,end);
          start = index + 1;
          end = index + 1;
		}
      index++;
	}
	end = index - 1;
	reverse(input,start,end);
}
