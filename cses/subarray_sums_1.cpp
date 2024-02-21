#include <iostream>
#include <queue>
 
using namespace std;
 
int main() {
	int n, x;
	cin >> n >> x;
 
	int csum = 0;
	int a;
	queue<int> kol;
	int out = 0;
	for (int i = 0; i < n; i++) {
		cin >> a;
		csum += a;
		kol.push(a);
		while (csum > x) {
			csum -= kol.front();
			kol.pop();
		}
		if (csum == x) {
			out++;
		}
	}
 
	cout << out;
 
	return 0;
}