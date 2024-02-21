#include <iostream>
#include <queue>
#include <map>
 
using namespace std;
 
int main() {
	int x, n;
	cin >> x >> n;
 
	priority_queue<int, vector<int>, greater<int>> places;
	vector<int> order;
	map<int, int> vals;
 
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		places.push(a);
		order.push_back(a);
	}
 
	int last = 0;
	int tmp;
	priority_queue<int> sizes;
	while (places.size()) {
		tmp = places.top();
		vals[tmp] = tmp - last;
		sizes.push(vals[tmp]);
		last = tmp;
		places.pop();
	}
 
	vals[x + 1] = x - last;
	sizes.push(x - last);
 
	vector<int> out;
	while (order.size()) {
		out.push_back(sizes.top());
		a = order.back();
		order.pop_back();
		tmp = vals.upper_bound(a)->first;
		vals[tmp] += vals[a];
		vals.erase(a);
		sizes.push(vals[tmp]);
	}
 
	while (out.size()) {
		cout << out.back()<<" ";
		out.pop_back();
	}
	return 0;
}