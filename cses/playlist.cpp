#include <iostream>
#include <map>
 
using namespace std;
 
int main() {
	int n;
	cin >> n;
 
	int* lastSame = new int[n] {0};
	map<int,int> last;
	int a;
	for (int i = 0; i < n; i++) {
		lastSame[i] = -1;
		cin >> a;
		if (last.find(a) != last.end()) {
			lastSame[i] = last.find(a)->second;
		}
 
		last[a] = i;
	}
 
	int s = 0;
	int out = 0;
 
	for (int i = 0; i < n; i++) {
		if (lastSame[i] >= s) {
			s = lastSame[i] + 1;
		}
		if (i - s+1 > out) out = i - s+1;
	}
 
	cout << out;
 
	return 0;
}