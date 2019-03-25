int partition(int a[], int si, int ei){
    int c  = a[si], i = si + 1;
    int count = 0;
    
    while(i <= ei){
        if(a[i] <= c){
            count++;
        }
        i++;
    }
    
    int count_index = count + si;
    
    int temp = a[si];
    a[si] = a[count_index];
    a[count_index] = temp;
    
    c = a[count_index];
    i = si;
    int j = ei;
    
    while(i < count_index && j > count_index){
        if(a[i] <= c){
            i++;
        }
        else if(a[j] > c){
            j--;
        }
        else{
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;            
        }
    }
    return count_index;
}

void quickSort(int a[], int start, int end){
    if(start >= end){
        return;
    }
    
    int c = partition(a, start, end);
    quickSort(a, start, c - 1);
    quickSort(a, c + 1, end);
}

void quickSort(int input[], int size) {
    quickSort(input, 0, size - 1);
}