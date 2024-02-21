#include <iostream>
#include <queue>

using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int maxW;
	cin >> maxW;
	int n;
	cin >> n;
	priority_queue<int> weights;
	priority_queue<int, vector<int>, greater<int> > Sweights;
	int b;
	for (int i = 0; i < n; i++) {
		cin >> b;
		weights.push(b);
		Sweights.push(b);
	}

	int tmp = 0;
	int out = 1;
	while (weights.size()+Sweights.size()>n) {
		bool doneSomething = false;
		if (weights.top() + tmp <= maxW) {
			doneSomething = true;
			tmp += weights.top();
			weights.pop();
		}

		if (Sweights.top() + tmp <= maxW) {
			doneSomething = true;
			tmp += Sweights.top();
			Sweights.pop();
			doneSomething = true;
		}

		if (!doneSomething) {
			out++;
			tmp = 0;
		}

	}
	cout << out;

	return 0;
}