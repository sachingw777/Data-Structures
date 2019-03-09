bool isSorted(int a[], int size){
    if(size ==0 || size == 1){
        return true;
    }

    if(a[0] > a[1]){
        return false;
    }

    bool isSmallSorted = isSorted(a+1, size-1);
    return isSmallSorted;
}