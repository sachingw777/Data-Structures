void insertion_sort(int a[], int n){
    for(int i = 1; i < n; i++){
        key = a[i];
        j = i -1;
        
        while(j >= 0 && a[j] > key){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}