#include <iostream>
using namespace std;

int fib_DP(int n) {	//DP. O(n).
	int *ans = new int[n+1];

	ans[0] = 0;
	ans[1] = 1;

	for(int i = 2; i <= n; i++) {
		ans[i] = ans[i-1] + ans[i-2];
	}
	return ans[n];
}

int fib_2(int n, int *ans) {	//Memoization. O(n). 
	if(n <= 1){
		ans[n] = n;	//save before returning. ans[0] = 0, ans [1] = 1
		return n;
	}

	if(ans[n - 1] == 0){
		ans[n - 1] = fib_2(n - 1, ans);
	}

	if(ans[n - 2] == 0){
		ans[n - 2] = fib_2(n - 2, ans);
	}

	ans[n] = ans[n - 1] + ans[n - 2];
	return ans[n];
}

int fib_2(int n) {
	int *ans = new int[n+1];

	for(int i = 0; i <= n; i++) {
		ans[i] = 0;
	}
	
	return fib_2(n, ans);
}

int fib(int n) {	//Brute Force. O(2^n).
	if(n <= 1) {
		return n;
	}
	int a = fib(n - 1);
	int b = fib(n - 2);
	return a + b;
}

int main() {
	int n;
	cin >> n;
	cout << fib_2(n) << endl;
	cout << fib_DP(n) << endl;
	cout << fib(n) << endl;
}