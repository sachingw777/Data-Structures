#include <iostream>
using namespace std;
#include <cmath>


int balancedBTs(int h) {
	if(h <= 1){
		return 1;
	}

	int x = balancedBTs(h - 1);
	int y = balancedBTs(h - 2);

	int mod = (int) (pow(10,9)) + 7;
	int temp1 = (int) (((long)(x) * x) % mod);
	int temp2 = (int) ((2 * (long)(y) * x) % mod);
	int ans = ((temp1 + temp2) % mod);
	return ans;
}

int main() {
    int h;
    cin >> h;
    int ans = balancedBTs(h);
    cout << ans << endl;
}
