#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
 
using namespace std;
 
int main() {
	int n;
	cin >> n;
 
	vector<int> lengths;
	int a;
 
	for (int i = 0; i < n; i++) {
		cin >> a;
		lengths.push_back(a);
	}
 
	sort(lengths.begin(), lengths.end());
	int median = lengths[(n - 1) / 2];
 
	long long out = 0;
	for (int i = 0; i < n; i++) {
		out += abs(lengths[i] - median);
	}
 
	cout << out;
	return 0;
}