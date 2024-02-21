#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	
	long long n, m, k;
	long long* numberOfPigmet;
	for (int i = 0; i < t; i++) {
		bool isPossible = false;
		cin >> n >> m >> k;
		numberOfPigmet = new long long[k];
		for (int j = 0; j < k; j++) {
			cin >> numberOfPigmet[j];
		}

		long long additionalRows = 0;
		long long rowsLeft = m;
		for (int j = 0; j < k; j++) {
			if (numberOfPigmet[j] / n >= 2 && rowsLeft>1) {
				rowsLeft -= 2;
				if (numberOfPigmet[j] / n > 2) {
					additionalRows += (numberOfPigmet[j] / n) - 2;
				}
			}
			else if (rowsLeft == 1&&additionalRows==0) {
				if (numberOfPigmet[j] / n >= 3) {
					isPossible = true;
				}
			}
			if (rowsLeft - additionalRows <= 0) {
				isPossible = true;
				break;
			}
		}

		if (!isPossible) {

			additionalRows = 0;
			rowsLeft = n;
			for (int j = 0; j < k; j++) {
				if (numberOfPigmet[j] / m >= 2 && rowsLeft > 1) {
					rowsLeft -= 2;
					if (numberOfPigmet[j] / m > 2) {
						additionalRows += (numberOfPigmet[j] / m) - 2;
					}
				}
				else if (rowsLeft == 1 && additionalRows == 0) {
					if (numberOfPigmet[j] / m >= 3) {
						isPossible = true;
					}
				}
				if (rowsLeft - additionalRows <= 0) {
					isPossible = true;
					break;
				}
			}
		}

		if (isPossible)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}