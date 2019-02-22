void SortZeroesAndOne(int arr[], int size){

int left = 0, right = size-1;
    while (left < right){
        while (arr[left] == 0 && left < right) left++;
        while (arr[right] == 1 && left < right) right--;
        if (left < right){
            arr[left] = 0;
            arr[right] = 1;
            left++;
            right--;
        }
    }
}

  
  /*Code 2
  int i = 0, j = size - 1;
  while(i < j){
    if(arr[i] == 0){
		i++;
    }
    if(arr[j] == 1){
        j--;
    }
    
    else if(arr[i] == 1 && arr[j] == 0){
         arr[i] = 0;
         arr[j] = 1;
         i++;
         j--;
       }
  }
}*/
    