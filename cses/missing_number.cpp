#include <iostream>
 
using namespace std;
 
int main() {
 
	int n, ogn;
	cin >> n;
	ogn = n;
 
	bool* used = new bool[n+1] {0};
	int a;
	while (--n) {
		cin >> a;
		used[a] = 1;
	}
 
	for (int i = 1; i <= ogn; i++) {
		if (!used[i]) {
			cout << i;
			break;
		}
	}
}