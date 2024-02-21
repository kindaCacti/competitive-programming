#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	int n, m;
	cin >> n >> m;
 
	map<int, int> price;
 
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		price[-a]++;
	}
 
	int tmp;
	while (m--) {
		cin >> a;
		a = -a;
		if (price.lower_bound(a) == price.end()) {
			cout << "-1\n";
			continue;
		}
 
		tmp = price.lower_bound(a)->first;
 
		cout << -tmp << endl;
		price[tmp]--;
		if (price[tmp] == 0) {
			price.erase(tmp);
		}
	}
 
 
	return 0;
}