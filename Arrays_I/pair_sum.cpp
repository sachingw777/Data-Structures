#include <algorithm>
using namespace std;

void pairSum(int input[], int size, int x) {
  sort(input,input + size);
  for(int i = 0; i < size-2;i++){
  	int j = size-1;
    while(j > i){
		int sum = input[i] + input[j];
      	if(sum == x) {
			cout << input[i] << " " << input[j] << endl;
          	j--;
         }
        else if(sum < x){
        	break;
        }else{
        	j--;
        }
    }
  }
}

  /* another way
  sort(input, size+ input);
  int i = 0, j = size - 1;

  while(i < j){
    int sum = input[i] + input[j];
	if(sum = x){
		j--;
      i++;
    }
    else if(sum > x){
		j--;
      i=0;
    }
    else{
      i++;
    }
  }
  */