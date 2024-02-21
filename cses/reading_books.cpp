#include <iostream>
 
using namespace std;
 
int main() {
	int n;
	cin >> n;
 
	long long sum = 0;
	int mx = 0;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		mx = ((mx > a) ? mx : a);
		sum += a;
	}
 
	if (mx * 2 <= sum) cout << sum;
	else {
		cout << mx * 2;
	}
 
	return 0;
}