void merge(int input[], int start, int mid, int end) 
{ 
    int i, j, k; 
    int size1 = mid - start + 1; 
    int size2 =  end - mid; 
  
    int L[size1], R[size2]; 
  
    for (i = 0; i < size1; i++) {
        L[i] = input[i + start]; 
    }

    for (j = 0; j < size2; j++){
        R[j] = input[j + mid + 1]; 
    } 
  
    i = 0, j = 0;
    k =  start;
    while (i < size1 && j < size2) 
    { 
        if (L[i] <= R[j]) 
        { 
            input[k] = L[i]; 
            i++; 
        } 
        else
        { 
            input[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 

    while (i < size1) 
    { 
        input[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < size2) 
    { 
        input[k] = R[j]; 
        j++; 
        k++; 
    } 
}

void mergeSort(int input[], int start, int end){
    if(start >= end){
        return;
    }

    int mid = (start + end)/2;
    mergeSort(input, start, mid);
    mergeSort(input, mid + 1, end);
    merge(input, start, mid, end);
}

void mergeSort(int input[], int size){
    mergeSort(input, 0, size - 1);
}