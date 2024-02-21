#include <iostream>
#include <vector>
#include <set>
 
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
	int tmp, tmp2, tmp3;
	int highest = 1;
	set<int> divs;
	set<int> donern;
	vector<int> cdivs;
	bool* been = new bool[1000002] {0};
	//bool* beenrn = new bool[1000002] {0};
	//set<int> beenrn;
 
	while (n--) {
		donern.clear();
		cdivs = { 1 };
		//beenrn.clear();
		cin >> x;
 
		for (int i = 0; i < primes.size(); i++) {
			tmp = 0;
			if (primes[i] > x) break;
			while (x % primes[i] == 0) {
				x /= primes[i];
				tmp++;
			}
			tmp2 = 1;
			tmp3 = cdivs.size()-1;
			for (int k = 0; k < tmp; k++) {
				tmp2 *= primes[i];
				for (int j = tmp3; j >= 0; j--) {
					//if (beenrn.find(cdivs[j] * tmp2) != beenrn.end()) continue;
					cdivs.push_back(cdivs[j] * tmp2);
					//beenrn.insert(cdivs[j] * tmp2);
					if (been[cdivs[j] * tmp2] && highest < cdivs[j] * tmp2) highest = cdivs[j] * tmp2;
					else been[cdivs[j] * tmp2] = 1;
				}
			}
		}
		if (x > 1) {
			for (int j = cdivs.size() - 1; j >= 0; j--) {
				cdivs.push_back(cdivs[j] * x);
				if (been[cdivs[j] * x] && highest < cdivs[j] * x) highest = cdivs[j] * x;
				else been[cdivs[j] * x] = 1;
			}
		}
	}
 
	cout << highest;
}