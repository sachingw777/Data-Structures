#include <string.h>
void reverse(char input[], int i, int j) {
	while(i < j) {
		int temp = input[i];
		input[i] = input[j];
		input[j] = temp;
		i++;
		j--;
	}
}

void reverseStringWordWise(char input[]) {
  int i =0, j = strlen(input) - 1;
  int length = strlen(input);
  reverse(input, i, j);

  i =0,j=0;
  int index = 0;
  while(index < length ) {
	if(input[index] == ' ') {
      j = index - 1;
      reverse(input, i, j);
      i = index + 1;
      j = index + 1;
    }
  	index++;
  }

  j = index - 1;
  reverse(input, i, j);
}