#include <iostream>
 
using namespace std;
 
int main() {
	int n, q;
	cin >> n >> q;
 
	long long* presum = new long long[n + 1] {0};
	for (int i = 0; i < n; i++) {
		cin >> presum[i + 1];
		presum[i + 1] += presum[i];
	}
 
	int a, b;
	while (q--) {
		cin >> a >> b;
		a--;
		cout << (presum[b] - presum[a]) << endl;
	}
 
	return 0;
}