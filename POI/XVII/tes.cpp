#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	map<int, set<int> > nums;
	int a;

	for (int i = 0; i < n; i++) {
		cin >> a;
		nums[a].insert(i);
	}

	int nk;
	cin >> nk;
	for (int i = 0; i < nk; i++) {
		cin >> a;

		int b;
		int cp = -1;
		auto it = nums[0].begin();
		for (int j = 0; j < a; j++) {
			cin >> b;
			it = nums[b].upper_bound(cp);
			if (it == nums[b].end()) {
				cp = n;
			}else
				cp = *it;
		}
		if (cp == n) cout << "NIE\n";
		else cout << "TAK\n";
	}
	return 0;
}