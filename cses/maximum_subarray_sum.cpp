#include <iostream>
 
using namespace std;
 
int main() {
	int n;
	cin >> n;
 
	long long* presums = new long long[n + 1] {0};
	//long long min = 0;
	//long long max = 0;
	long long out = 0;
	int maxval = -1000000000;
	int a;
 
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a > maxval) maxval = a;
		
		presums[i + 1] = presums[i] + a;
	}
 
	int min=0, max=1;
	out = maxval;
	for (int i = 0; i < n; i++) {
		if (presums[i + 1] < presums[min]) {
			min = i + 1;
			max = i + 1;
		}
		else if (presums[i + 1] > presums[max]) {
			max = i + 1;
		}
 
		if (min!=max&&presums[max] - presums[min] > out) {
			out = presums[max] - presums[min];
		}
	}
 
	cout << out;
 
	return 0;
}