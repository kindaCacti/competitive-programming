#include <iostream>
 
using namespace std;
 
bool canBeDone(int n, int t, long long ti, int*& times) {
	long long out = 0;
	for (int i = 0; i < n; i++) {
		out += ti / times[i];
		if (out > t) break;
	}
	return (out >= t);
}
 
int main() {
	int n, t;
	cin >> n >> t;
 
	int* times = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> times[i];
	}
 
	long long min = 0;
	long long max = 1e18;
	long long mid;
 
	while (min < max) {
		mid = (max - min) / 2 + min;
		if (canBeDone(n, t, mid, times)) {
			max = mid;
		}
		else {
			min = mid + 1;
		}
	}
 
	cout << min;
	return 0;
}
