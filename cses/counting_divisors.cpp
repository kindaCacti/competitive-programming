#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
	int n;
	cin >> n;
 
	bool* sieve = new bool[1002] {0};
	for (int i = 2; i * i <= 1001; i++) {
		if (sieve[i])continue;
		for (int j = i * i; j <= 1001; j += i) {
			sieve[j] = 1;
		}
	}
 
	vector<int> primes;
 
	for (int i = 2; i < 1002; i++) {
		if (!sieve[i]) {
			primes.push_back(i);
		}
	}
 
	int x;
	long long out;
	int tmp;
 
	while (n--) {
		cin >> x;
		out = 1;
 
		for (int i = 0; i < primes.size(); i++) {
			tmp = 0;
			while (x % primes[i] == 0) {
				tmp++;
				x /= primes[i];
			}
 
			out *= (tmp+1);
		}
 
		if (x > 1) out *= 2;
 
		cout << out << endl;
	}
}