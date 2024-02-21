#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
	//const long long max = 1e18;
	long long n, k;
	cin >> n >> k;
	vector<long long>* divs = new vector<long long>[k];
	vector<long long> inputs;
 
	long long a;
	for (int i = 0; i < k; i++) {
		cin >> a;
		inputs.push_back(a);
	}
 
	long long out = 0;
	int mul = 1;
 
	for (int i = 0; i < k; i++) {
		for (int j = k - 2; j >= 0; j--) {
			for (int l = 0; l < divs[j].size(); l++) {
				if (n / divs[j][l] >= inputs[i]) {
					divs[j + 1].push_back(divs[j][l] * inputs[i]);
				}
			}
		}
		divs[0].push_back(inputs[i]);
	}
 
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < divs[i].size(); j++) {
			out += ((n / divs[i][j]) * mul);
		}
		mul = -mul;
	}
 
	cout << out;
 
	return 0;
}
