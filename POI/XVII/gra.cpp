#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	priority_queue<int, vector<int>, greater<int>> cards;

	cin >> n;

	int a;
	while (n--) {
		cin >> a;
		cards.push(a);
	}

	long long minval = 0;
	long long maxval = 0;
	long long tminval = 0;
	long long tmaxval = 0;
	int tmp = 0;

	while (cards.size()) {
		tmp = cards.top();
		cards.pop();

		tminval = minval;
		tmaxval = maxval;

		if (maxval < tminval + tmp) maxval = tminval + tmp;

		if (minval > tmaxval - tmp) minval = tmaxval - tmp;
	}

	cout << maxval;

	return 0;
}