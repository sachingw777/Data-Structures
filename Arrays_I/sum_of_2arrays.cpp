// arr - input array
// size - size of array
void Reverse(int arr[],int size) 
{
    int temp=0;
    for(int i=0,j=size-1;i<j;i++,j--)
    {
        temp = arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
}

