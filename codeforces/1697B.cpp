#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	long long* sums = new long long[n+1]{0};
	priority_queue<int> vals;

	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		vals.push(a);
	}

	int i = 0;

	long long tmpsum = 0;
	while (vals.size()) {
		tmpsum += vals.top();
		sums[i+1] = tmpsum;
		vals.pop();
		i++;
	}

	int b;
	for (int j = 0; j < q; j++) {
		cin >> a >> b;
		cout << sums[a] - sums[a - b]<<"\n";
	}
}