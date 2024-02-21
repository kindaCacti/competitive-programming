#include <iostream>
#include <map>
 
using namespace std;
 
int main() {
	int n, x;
	cin >> n >> x;
 
	map<int, int> prevs;
	int a;
	bool done = false;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (!done&&prevs.find(x - a) != prevs.end()) {
			done = true;
			cout << prevs[x - a] << " " << i + 1;
		}
		prevs[a] = i+1;
	}
 
	if (!done) {
		cout << "IMPOSSIBLE";
	}
 
	return 0;
}