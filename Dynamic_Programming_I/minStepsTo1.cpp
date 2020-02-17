#include <iostream>
#include <climits>
using namespace std;

int countStepsTo1_optimized(int n, int* ans){
	if(n == 1){
		ans[n] = 0;
		return 0;
	}

	if(ans[n-1] == -1){
		ans[n-1] = countStepsTo1_optimized(n-1, ans);
	}

	int x = INT_MAX, y = INT_MAX;
	if(n % 2 == 0){
		if(ans[n/2] == -1){
			ans[n/2] = countStepsTo1_optimized(n/2, ans);
		}
		x = ans[n/2];
	}	
	if(n % 3 == 0){
		if(ans[n/3] == -1){
			ans[n/3] = countStepsTo1_optimized(n/3, ans);
		}
		y = ans[n/3];
	}

	ans[n] = min(ans[n-1], min(x,y)) + 1;
	return ans[n];
}

int countStepsTo1_optimized(int n){
	int* ans = new int[n + 1];
	for(int i = 0; i <= n; i++) {
		ans[i] = -1;
	}
	return countStepsTo1_optimized(n, ans);
}

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
	// cout << countStepsTo1(n) << endl;
	cout << countStepsTo1_optimized(n) << endl;
}