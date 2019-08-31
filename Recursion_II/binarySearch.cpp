int binarySearch(int input[], int si, int ei, int element){
    if(si <= ei){
        int mid = (si + ei) / 2;
        
        if(input[mid] == element){
            return mid;
        }
        else if(input[mid] < element){
            return binarySearch(input, mid + 1, ei, element); 
        }
        else if(input[mid] > element){
            return binarySearch(input, si, mid - 1, element);
        }
    }
    return -1;
}

int binarySearch(int input[], int size, int element) {
    return binarySearch(input, 0, size - 1, element);
}