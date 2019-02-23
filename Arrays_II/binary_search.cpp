// arr - input array
// n - size of array
// val - element to be searched
int BinarySearch(int arr[], int n, int val)
{	
    int start=0,
  	end=n-1,
 	 mid;
    
	while(start<end)
	{
	    mid=(start+end)/2;
	    if(arr[mid]>val)
	        end=mid-1;
	    else if(arr[mid]<val)
	        start = mid+1;
	    else if(arr[mid]==val)
	        return mid;
	}
	return -1;

}

