int FindSortedArrayRotation(int arr[], int n) {
    // Write your code here
    int min_index = 0;


    for(int i = 0; i < n; i++)
    {
        if(arr[min_index] > arr[i]){
            min_index = i;
        }
    }
    return min_index;
}