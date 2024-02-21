#include <iostream>
#include <vector>
#include <set>
#include <queue>

#define mil 1000000

using namespace std;

vector<int> primes;
set<int> primesset;

void generatePrimes() {
	bool* isNotPrime = new bool[mil]{0};
	for (int i = 2; i * i <= mil; i++) {
		if (isNotPrime[i])
			continue;
		for (int j = i * i; j <= mil; j += i) {
			isNotPrime[j] = true;
		}
	}

	for (int i = 3; i < mil; i++) {
		if (!isNotPrime[i]) {
			primes.push_back(i);
			primesset.insert(i);
		}
	}
}

vector<int> getInSize(long long n) {

	vector<int> out;

	int i = primes.size()-1;

	while (n > primes[i] && n - primes[i] > 10) {
		n -= primes[i];
		out.push_back(primes[i]);
		i--;
	}

	i = 0;

	while (n - primes[i] > 1000||n-primes[i]>primes[i]) {
		i++;
	}
	out.push_back(primes[i]);
	return out;
}

int makeDivisibleBy2(long long n) {
	int i = 0;

	for (; primes[i]<=n; i++) {
		if (n - primes[i] < primes[i])
			return primes[i];
	}
	return 0;
}

int main() {
	generatePrimes();
	int t;
	cin >> t;
	
	long long n;
	vector<int> out;
	for (int ik = 0; ik < t; ik++) {
		out.clear();
		cin >> n;

		out = getInSize(n);
		for (int i = 0; i < out.size(); i++) {
			n -= out[i];
		}
		//now n should be at most 1000 with all the primes below n are still available to use

		if (n % 2 != 0 && n>=21) {
			out.push_back(makeDivisibleBy2(n));
			n -= out.back();
		}
		else if (n % 2 == 1 && n < 21) {
			if (n == 3) {
				out.push_back(3);
				
			}if (n == 5) {
				out.push_back(5);

			}if (n == 7) {
				out.push_back(7);

			}if (n == 11) {
				out.push_back(11);

			}if (n == 13) {
				out.push_back(13);

			}if (n == 15) {
				out.push_back(5);
				out.push_back(3);
				out.push_back(7);

			}if (n == 17) {
				out.push_back(17);

			}if (n == 19) {
				out.push_back(19);

			}

			n = 0;
		}

		if (n > 0) {
			for (int i = 0; primes[i] < n; i++) {
				if (primesset.find(n - primes[i]) != primesset.end()) {
					out.push_back(primes[i]);
					out.push_back(n - primes[i]);
					break;
				}
			}
		}

		priority_queue<int, vector<int>, greater<int>> nums;
		int i = -1;
		while (++i < out.size())
			nums.push(out[i]);

		cout << nums.size() << endl;
		while (nums.size()) {
			cout << nums.top() << " ";
			nums.pop();
		}
		cout<<endl;
	}
}