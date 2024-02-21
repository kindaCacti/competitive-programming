#include <iostream>
 
using namespace std;
 
bool isPossible(int n, int* nums, int k, long long s) {
	long long tmp = 0;
	int out = 0;
	for (int i = 0; i < n; i++) {
		if (nums[i] > s) return false;
		if (nums[i] + tmp > s) {
			tmp = 0;
			out++;
		}
		tmp += nums[i];
	}
	if (tmp) out++;
 
	return ((out > k) ? false : true);
}
 
int main() {
	int n, k;
	cin >> n >> k;
	int* nums = new int[n];
 
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
 
	long long min = 0;
	long long max = 1e18;
	long long mid;
 
	while (min < max) {
		mid = ((max - min) / 2) + min;
		if (isPossible(n, nums, k, mid)) {
			max = mid;
		}
		else {
			min = mid + 1;
		}
	}
 
	cout << max;
 
	return 0;
}