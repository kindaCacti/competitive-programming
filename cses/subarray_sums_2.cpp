#include <iostream>
#include <queue>
#include <map>
 
using namespace std;
 
int main() {
	long long n, x;
	cin >> n >> x;
 
	long long csum = 0;
	int a;
	queue<int> kol;
	long long out = 0;
	map<long long, int> vals;
	vals[0] = 1;
	for (int i = 0; i < n; i++) {
		cin >> a;
		csum += a;
		if (vals.find(csum-x) != vals.end()) {
			out += vals[csum-x];
		}
		vals[csum]++;
	}
 
	cout << out;
 
	return 0;
}