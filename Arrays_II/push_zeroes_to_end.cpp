void PushZeroesEnd(int arr[], int n)
{
    int k = 0, i = 0;
    while(i < n ){
        if(arr[i] != 0){
            arr[k] = arr[i];
            i++;
            k++;
        }else{
            i++;
        }
    }
    while(k < n){
        arr[k] = 0;
        k++;
    }
}