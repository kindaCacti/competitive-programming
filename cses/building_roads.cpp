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
	vector<int> queue;
	int cn, nn;
 
	for (int i = 0; i < n; i++) {
		if (used[i]) continue;
 
		unions.push_back({});
 
		queue.clear();
		queue.push_back(i);
 
		while (queue.size()) {
			cn = queue.back();
			queue.pop_back();
			used[cn] = 1;
			unions.back().push_back(cn);
 
			for (int j = 0; j < edges[cn].size(); j++) {
				nn = edges[cn][j];
				if (used[nn]) continue;
				used[nn] = 1;
				queue.push_back(nn);
			}
		}
	}
 
	cout << unions.size() - 1 << endl;
	for (int i = 0; i < unions.size() - 1; i++) {
		cout << unions[i].back()+1 << " " << unions[i + 1].back()+1 << "\n";
	}
	return 0;
}