#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
	int n, x;
	cin >> n >> x;
 
	vector<int> weights;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		weights.push_back(a);
	}
 
	int i = 0, j = n - 1;
	sort(weights.begin(), weights.end());
 
	int out = 0;
	while (i <= j) {
		out++;
		if (weights[i] + weights[j] <= x) {
			i++;
		}
		j--;
	}
 
	cout << out;
	return 0;
}