#include <iostream>
 
using namespace std;
 
int main() {
	int n;
	cin >> n;
 
	long long* poss = new long long[n + 1]{0};
 
	poss[0] = 1;
 
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= 6; j++) {
			if (i + j > n) break;
 
			poss[i + j] += poss[i];
			poss[i + j] %= 1000000007;
		}
	}
 
	cout << poss[n];
}