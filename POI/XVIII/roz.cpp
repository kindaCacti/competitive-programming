#include <iostream>
#include <map>

using namespace std;

int checkdiff(int a, int b, int* &nextOccurrence, int* &start) {
	int cmaxdiff = 0;
	int tmp = 0;
	int ca = start[a];
	int cb = start[b];
	bool usedb = true;;

	if (cb == -1) return 0;
	if (ca == -1) return 0;

	if (cb < ca) {
		usedb = true;
		while (cb < ca&&cb!=-1) {
			tmp--;
			cb = nextOccurrence[cb];
		}
	}

	if (tmp < 0) {
		tmp = 1;
		usedb = 0;
	}

	else if (tmp > cmaxdiff&&usedb) {
		cmaxdiff = tmp;
	}

	while (ca != -1) {
		ca = nextOccurrence[ca];
		if (ca == -1) break;
		tmp++;
		while (ca > cb&&cb!=-1) {
			tmp--;
			usedb = true;
			cb = nextOccurrence[cb];
		}
		if (tmp <= 0) {
			tmp = 1;
			usedb = false;
		}
		else if (tmp > cmaxdiff&&usedb) {
			cmaxdiff = tmp;
		}
		else if (tmp - 1 > cmaxdiff) {
			cmaxdiff = tmp - 1;
		}
	}

	return cmaxdiff;
}

int main() {
	int n;
	cin >> n;

	char* vals = new char[n];

	for (int i = 0; i < n; i++) {
		cin >> vals[i];
	}

	int* nextOccurrence = new int[n] {0};
	int* start = new int[26]{ 0 };
	map<char, int> lastOccurrence;
	for (int i = n - 1; i >= 0; i--) {
		if (lastOccurrence.find(vals[i]) == lastOccurrence.end()) {
			nextOccurrence[i] = -1;
		}
		else {
			nextOccurrence[i] = lastOccurrence[vals[i]];
		}

		lastOccurrence[vals[i]] = i;
	}

	for (int i = 0; i < 26; i++) {
		if (lastOccurrence.find((char)('a' + i)) == lastOccurrence.end())
			start[i] = -1;
		else
			start[i] = lastOccurrence[(char)('a' + i)];
	}


	int maxdiff = 0;
	int tmp = 0;
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			if (i == j) continue;

			tmp = checkdiff(i, j, nextOccurrence, start);
			if (tmp > maxdiff) maxdiff = tmp;
		}
	}

	cout << maxdiff;
	return 0;
}