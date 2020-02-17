#include <iostream>
#include <climits>
using namespace std;

int countStepsTo1(int n){
	if(n == 1){
		return 0;
	}

	int ans1 = countStepsTo1(n - 1);
	int ans2 = INT_MAX, ans3 = INT_MAX;
	if(n % 2 == 0){
		ans2 = countStepsTo1(n / 2);
	}

	if(n % 3 == 0){
		ans3 = countStepsTo1(n / 3);
	}

	return min(ans1, min(ans2, ans3)) + 1;
}

int main(){
	int n;
	cin  >> n;
	cout << countStepsTo1(n) << endl;
}