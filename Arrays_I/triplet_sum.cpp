// arr - input array
// size - size of array
// x - sum of triplets
#include<algorithm>
void TripletSum1(int input[],int size,int x)	
{
	for (int i = 0; i <= size-3; i++)
	{
		for(int j=i+1; j<= size-2; j++)
		{
			for(int k=j+1; k<=size-1;k++)
			{
				int sum = input[i] + input[j] + input[k];

				if(sum == x){
					cout << input[i]<<" "<<input[j]<<" "<<input[k] <<endl;
				}else if(sum > x){
                  break;
                }
			}
		}
	}
}

void FindTriplet(int arr[], int size, int x) {
	// Write your code here
  	sort(arr, size + arr);
    TripletSum1(arr,size,x);
}