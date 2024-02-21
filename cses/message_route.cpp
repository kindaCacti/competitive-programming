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
 
	vector<int> queue = {0};
	int cn;
	int* away = new int[n] {0};
	away[0] = 1;
	int k = 0;
 
	while (k!=queue.size()) {
		cn = queue[k];
 
		for (int nn : edges[cn]) {
			if (away[nn] != 0) continue;
 
			away[nn] = away[cn] + 1;
			queue.push_back(nn);
		}
		k++;
	}
 
	if (!away[n - 1]) {
		cout << "IMPOSSIBLE";
		return 0;
	}
 
	cout << away[n-1] << endl;
 
	vector<int> route = {n-1};
 
	cn = n - 1;
	while (cn != 0) {
		for (int nn : edges[cn]) {
			if (away[nn] < away[cn]) {
				cn = nn;
				route.push_back(nn);
				break;
			}
		}
	}
 
	while (route.size()) {
		cout << route.back()+1 << " ";
		route.pop_back();
	}
	return 0;
}
