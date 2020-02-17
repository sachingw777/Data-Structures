#include<iostream>
using namespace std;

long staircase_DP(int n){
	long* ans = new long[n + 1];
	ans[0] = 1;
	ans[1] = 1;
	ans[2] = 2;

	for(int i = 3; i <= n; i++){
		ans[i] = ans[i-1] + ans[i-2] + ans[i-3];
	}
	long output = ans[n];
	delete [] ans;
	return output;
}

long staircase_optimized(int n, int* ans){
	if(n < 0){
		return 0;
	}

	if(n == 1 || n == 0){
		return 1;
	}

	if(ans[n - 1] == -1){
		ans[n - 1] = staircase_optimized(n - 1, ans);
	}
	if(ans[n - 2] == -1){
		ans[n - 2] = staircase_optimized(n - 2, ans);
	}
	if(ans[n - 3] == -1){
		ans[n - 3] = staircase_optimized(n - 3, ans);
	}

	ans[n] = ans[n-1] + ans[n-2] + ans[n-3];
	return ans[n];
}

long staircase_optimized(int n){
	int* ans = new int[n + 1];
	for(int i = 0; i <= n; i++) {
		ans[i] = -1;
	}

	int output = staircase_optimized(n, ans);
	delete [] ans;
	return output;
}

long staircase(int n){
    if(n < 0){
    	return 0;
    }

    if(n == 1 || n == 0){
    	return 1;
    }

	return staircase(n - 1) + staircase(n - 2) + staircase(n - 3);
}

int main(){
	int n; 
	cin >> n ;
	// cout << staircase(n) << endl;
	cout << staircase_optimized(n) << endl;
	cout << staircase_DP(n) << endl;
}