#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	int n;
	cin >> n;
 
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> films;
 
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		films.push({ a,b });
	}
 
	int fin = 0;
	int out = 0;
	pair<int, int> tmp;
 
	while (films.size()) {
		tmp = films.top();
		films.pop();
 
		if (tmp.first >= fin) {
			out++;
			fin = tmp.second;
		}
		else if (tmp.second < fin) {
			fin = tmp.second;
		}
	}
 
	cout << out;
}