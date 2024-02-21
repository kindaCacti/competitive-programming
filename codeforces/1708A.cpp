#include <iostream>

using namespace std;

int main() {
	int q;
	cin >> q;
	int* vals = new int[100000];
	for (int i = 0; i < q; i++) {
		int n;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> vals[j];
		}

		bool isPossible = true;
		for (int j = 1; j < n; j++) {
			if (vals[j] % vals[0])
				isPossible = false;
		}
		if (isPossible)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	
	return 0;
}