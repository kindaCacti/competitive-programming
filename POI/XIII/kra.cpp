#include <iostream>
#include <map>
#include <map>

using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n, nk;
	cin >> n >> nk;
	int max = -1;

	map<int, int> widthToDepth;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (max == -1 || max > a) {
			widthToDepth[-a] = i;
			max = a;
		}
	}

	int height = n+1;

	for (int i = 0; i < nk; i++) {
		cin >> a;
		map<int, int>::iterator itlow;
		itlow = widthToDepth.lower_bound(-(a-1));
		int tmp = height-1;
		if (itlow != widthToDepth.end() && widthToDepth[itlow->first] < height) tmp = widthToDepth[itlow->first];
		//cout << tmp;
		height = tmp;
		if (height <= 0) {
			cout << 0;
			break;
		}
	}
	if (height > 0) cout << height;

	return 0;
}