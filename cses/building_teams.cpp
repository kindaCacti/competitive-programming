#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
	int n, m;
	cin >> n >> m;
 
	vector<int>* edges = new vector<int>[n];
 
	int a, b;
 
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		a--; b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
 
	vector<vector<int>> unions;
	bool* used = new bool[n] {0};
	int* number = new int[n] {0};
	vector<int> queue;
 
	int cn;
	bool possible = true;
	for (int i = 0; i < n; i++) {
		if (used[i]) continue;
 
		queue = { i };
		number[i] = 1;
		while (queue.size()) {
			cn = queue.back();
			queue.pop_back();
 
			if (used[cn]) continue;
			used[cn] = 1;
 
			for (int nn : edges[cn]) {
				if (used[nn]) continue;
				queue.push_back(nn);
				if (number[nn] != 0 && number[nn] != (number[cn]) % 2 + 1) possible = false;
				number[nn] = (number[cn]) % 2 + 1;
			}
		}
	}
 
	if (!possible) {
		cout << "IMPOSSIBLE";
		return 0;
	}
 
	for (int i = 0; i < n; i++) {
		cout << number[i] << " ";
	}
 
	return 0;
}