
// arr - input array
// n - size of array

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}

void BubbleSort(int arr[], int n){
	// Write your code here
	int temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                //swap(&arr[j], &arr[j+1]);
              temp = arr[j+1];
              arr[j+1] = arr[j];
              arr[j] = temp;
            }
        }
    }
}
