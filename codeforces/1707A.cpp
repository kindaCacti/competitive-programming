#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	int* vals = new int[100000];
	bool* out = new bool[100000];
	for (int i = 0; i < t; i++) {
		int n, q;
		cin >> n >> q;
		int x = n / 2;

		for (int i = 0; i < n; i++)
			cin >> vals[i];

		int cq = 0;
		int sum = 0;
		int lastSum = 0;

		for (int i = n - 1; i >= 0; i--) {
			if (vals[i] <= cq)
				sum++;
			else {
				if (cq < q) {
					cq++;
					sum++;
				}
			}
			if (lastSum < sum) {
				lastSum = sum;
				out[i] = 1;
			}
			else
				out[i] = 0;
		}

		for (int i = 0; i < n; i++)
			cout << out[i];
		cout << "\n";
	}
}