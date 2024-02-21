#include <iostream>
#include <queue>

using namespace std;

int main() {
	int t;
	cin >> t;

	string a;
	for (int i = 0; i < t; i++) {
		cin >> a;
		if (a.size() <= 10) {
			cout << a << "\n";
			continue;
		}

		cout << a[0] << a.size() - 2 << a[a.size() - 1]<<"\n";
	}
}