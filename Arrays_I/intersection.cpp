// input1 - first array
// input2 - second array
// size1 - size of first array
// size2 - size of second array
#include<algorithm>
void intersection(int input1[], int input2[], int size1, int size2) {
  sort(input1, size1 + input1);
  sort(input2, size2 + input2);
  int i = 0, j = 0;
  
  while(i < size1 && j < size2){
      if(input1[i] == input2[j]){
        cout << input1[i] << endl;
        i++;
        j++;
      }
      
      else if(input1[i] < input2[j]){
        i++;
      }
      else{
        j++;
      }
  }
}
