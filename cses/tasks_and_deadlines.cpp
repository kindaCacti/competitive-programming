#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
	int n;
	cin >> n;
 
	int a, b;
	long long sumb = 0;
	vector<int> nums;
 
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		sumb += b;
		nums.push_back(a);
	}
 
	sort(nums.begin(), nums.end());
 
	long long tmp;
	for (int i = 0; i < n; i++) {
		tmp = (long long)nums[i] * (n - i);
		sumb -= tmp;
	}
 
	cout << sumb;
	return 0;
}