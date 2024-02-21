#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	int n;
	cin >> n;
 
	set<int> nums;
	int a;
	while (n--) {
		cin >> a;
		nums.insert(a);
	}
 
	cout << nums.size();
 
	return 0;
}