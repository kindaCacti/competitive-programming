#include <iostream>
#include <queue>
 
using namespace std;
 
int main() {
	int n;
	cin >> n;
 
 
	priority_queue<int, vector<int>, greater<int>> nums;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		nums.push(a);
	}
 
	long long to = 1;
 
	while (nums.size() && nums.top() <= to) {
		to += nums.top();
		nums.pop();
	}
 
	cout << to;
 
	return 0;
}