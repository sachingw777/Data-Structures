// arr - input array
// n - size of array
void SelectionSort(int arr[], int n) {
	// Write your code here
	
    for(int i=0;i<n-1;i++)
    {
      	int min = arr[i];     
        for(int j=i+1;j<n;j++)
        {
            if(min>arr[j])
            {
                min = arr[j];
                arr[j]=arr[i];
                arr[i]= min;
            }
        }
    }	
}
