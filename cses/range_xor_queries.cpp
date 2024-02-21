#include <iostream>
 
using namespace std;
 
int main() {
	int n, q;
	cin >> n >> q;
 
	long long* vals = new long long[n+1] {0};
 
	for (int i = 0; i < n; i++) {
		cin >> vals[i + 1];
		vals[i + 1] ^= vals[i];
	}
 
	int a, b;
	while (q--) {
		cin >> a >> b;
		a--;
		cout << (vals[b] ^ vals[a]) << endl;
	}
	return 0;
}