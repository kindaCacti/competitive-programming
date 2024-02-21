#include <iostream>
#include <set>
#include <vector>
 
using namespace std;
 
int main() {
	int n, m;
	cin >> n >> m;
 
	bool** map = new bool* [n]; //0-floor	1-wall
 
	char tmp;
 
	for (int i = 0; i < n; i++) {
		map[i] = new bool[m];
 
		for (int j = 0; j < m; j++) {
 
			cin >> tmp;
 
			if (tmp == '#')
				map[i][j] = 1;
			else
				map[i][j] = 0;
		}
	}
 
	set<pair<int, int>> used = {};
	int out = 0;
	pair<int, int> tmp2;
 
	vector<pair<int, int>> toCheck = {};
 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (used.find({ i, j }) != used.end()) continue;
			if (map[i][j]) continue;
 
			toCheck.clear();
			toCheck.push_back({ i, j });
 
			out++;
 
			while (toCheck.size()) {
				tmp2 = toCheck.back();
				toCheck.pop_back();
				
				if (used.find(tmp2) != used.end()) continue;
				if (map[tmp2.first][tmp2.second]) continue;
 
				used.insert(tmp2);
 
 
				for (int k = -1; k <= 1; k++) {
					for (int l = -1; l <= 1; l++) {
						if (k != 0 && l != 0) continue;
						if (k == 0 && l == 0) continue;
						if (tmp2.first + k < 0|| tmp2.first +k>=n) continue;
						if (tmp2.second + l<0 || tmp2.second + l>=m) continue;
 
						if(used.find({tmp2.first + k, tmp2.second + l}) == used.end() && !map[tmp2.first + k][tmp2.second + l])
							toCheck.push_back({ tmp2.first + k, tmp2.second + l });
					}
				}
			}
		}
	}
 
	cout << out;
	return 0;
}