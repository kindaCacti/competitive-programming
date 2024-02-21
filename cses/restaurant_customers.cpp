#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> enters, leaves;
 
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		enters.push(a);
		leaves.push(b);
	}
 
	int out = 0;
	int tmp = 0, tmp2;
	while (enters.size()) {
		tmp2 = enters.top();
		if (leaves.top() < tmp2) {
			tmp2 = leaves.top();
		}
 
		while (enters.size()&&enters.top() == tmp2) {
			tmp++;
			enters.pop();
		}
		while (leaves.size()&&leaves.top() == tmp2) {
			tmp--;
			leaves.pop();
		}
 
		if (tmp > out) {
			out = tmp;
		}
	}
 
	cout << out;
 
	return 0;
}