#include <iostream>
#include <map>
 
using namespace std;
 
int main() {
	int n;
	cin >> n;
 
	map<int, int> sizes;
	int a;
	int tmp;
	int out = 0;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (sizes.upper_bound(a) == sizes.end()) {
			sizes[a]++;
			out++;
		}
		else {
			tmp = sizes.upper_bound(a)->first;
			sizes[tmp]--;
			if (sizes[tmp] == 0) {
				sizes.erase(tmp);
			}
 
			sizes[a]++;
		}
	}
 
	cout << out;
	return 0;
}