// arr - input array
// size - size of array
void Reverse(int arr[],int size) {
  for(int i = 0, j = size - 1; i < j; i++, j--){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
}