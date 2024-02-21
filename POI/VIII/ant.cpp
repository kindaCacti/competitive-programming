#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct NODE {
	int divisors = 1;
	long long value = 1;
	int maxDivisor = 1;

	NODE() {
		divisors = 1;
		value = 1;
		maxDivisor = 1;
	}

	NODE(int divs, int maxDiv, long long val) {
		divisors = divs;
		value = val;
		maxDivisor = maxDiv;
	};
} root;

int maxDivs = 1;
int num = 1;
set<long long> usedVals;
void generateTree(vector<int>& primes, NODE pn, vector<NODE>& nodes, int*& translation, vector<int>& usedPrimes, long long& max, long long val = 1) {
	int divs;
	int maxDiv;
	for (int i = 0; i < primes.size(); i++) {
		val *= primes[i];
		if (val > max) {
			break;;
		}
		if (usedVals.find(val) != usedVals.end()) {
			val /= primes[i];
			continue;
		}
		if (i > 0 && usedPrimes[i - 1] < usedPrimes[i] + 1) {
			val /= primes[i];
			continue;
		}

		usedVals.insert(val);
		usedPrimes[translation[primes[i]]]++;
		divs = 1;

		maxDiv = 1;

		for (int j = 0; j < primes.size(); j++) {
			if (usedPrimes[translation[primes[j]]] == 0) break;
			maxDiv = primes[j];
			divs *= (usedPrimes[translation[primes[j]]] + 1);
			if (divs > maxDivs ||(divs==maxDivs&&num > val)) {
				num = val;
				maxDivs = divs;
			}
		}
		int cn = nodes.size();
		nodes.push_back(NODE(divs, maxDiv, val));
		generateTree(primes, nodes[cn], nodes, translation, usedPrimes, max, val);
		usedPrimes[translation[primes[i]]]--;
		val /= primes[i];

		if (primes[i] > pn.maxDivisor) break;
	}
}

int main() {
	long long n;
	cin >> n;

	vector<int> primes;

	int j;
	for (int i = 2; i < 50; i++) {
		j = 2;
		for (; j * j <= i; j++) {
			if (i % j == 0) {
				break;
			}
		}
		if (j * j > i) primes.push_back(i);
	}
	vector<NODE> nodes;
	vector<int> usedPrimes;
	int* translation = new int[51]{ 0 };
	int tmp = 0;
	for (int i = 0; i < primes.size(); i++) {
		usedPrimes.push_back(0);
		translation[primes[i]] = tmp;
		tmp++;
	}

	generateTree(primes, root, nodes, translation, usedPrimes, n);

	cout << num;
	return 0;
}