#include <iostream>
 
using namespace std;
 
int main() {
	int n;
	cin >> n;
 
	int* pos = new int[n] {0};
 
	int a;
	int out = 1;
	for (int i = 0; i < n; i++) {
		cin >> a;
		pos[a-1] = i + 1;
	}
 
	for (int i = 1; i < n; i++) {
		if (pos[i] < pos[i - 1]) {
			out++;
		}
	}
 
	cout << out;
}