#include <ibits/stdc++.h>
 
using namespace std;
 
int abs(int a) {
	return ((a > 0) ? a : -a);
}
 
int main() {
	int n, m, k;
	cin >> n >> m >> k;
 
	priority_queue<int> appartment, guest;
 
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		appartment.push(a);
	}
 
	for (int i = 0; i < m; i++) {
		cin >> a;
		guest.push(a);
	}
 
 
	int out = 0;
	while (appartment.size() && guest.size()) {
		if (abs(appartment.top() - guest.top()) <= k) {
			appartment.pop();
			guest.pop();
			out++;
		}
		else if (guest.top() > appartment.top()) {
			guest.pop();
		}
		else {
			appartment.pop();
		}
	}
 
	cout << out;
 
	return 0;
}