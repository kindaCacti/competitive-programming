#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
	int n, m;
	cin >> n >> m;
 
	bool** map = new bool* [n];
	int** dp = new int* [n];
	pair<int, int> start, finish;
	char tmp;
 
	for (int i = 0; i < n; i++) {
		map[i] = new bool[m]{0};
		dp[i] = new int[m]{0};
		for (int j = 0; j < m; j++) {
			cin >> tmp;
			if (tmp == 'A') start = { i, j };
			if (tmp == 'B') finish = { i, j };
			if (tmp == '#') map[i][j] = 1;
		}
	}
 
	vector<pair<int, int>> queue = { start };
	int x, y;
 
	dp[start.first][start.second] = 1;
 
	int k = 0;
	while (k<queue.size()) {
		x = queue[k].first;
		y = queue[k].second;;
 
		if (x - 1 >= 0&&dp[x-1][y]==0&&!map[x - 1][y]) {
			dp[x - 1][y] = dp[x][y] + 1;
			queue.push_back({ x-1, y });
		}
		if (x + 1 < n && dp[x + 1][y] == 0 && !map[x + 1][y]) {
			dp[x + 1][y] = dp[x][y] + 1;
			queue.push_back({ x + 1, y });
		}
		if (y - 1 >= 0 && dp[x][y-1] == 0 && !map[x][y - 1]) {
			dp[x][y-1] = dp[x][y] + 1;
			queue.push_back({ x, y - 1 });
		}
		if (y+1<m && dp[x][y+1] == 0 && !map[x][y + 1]) {
			dp[x][y+1] = dp[x][y] + 1;
			queue.push_back({ x, y+1 });
		}
 
		k++;
	}
 
	if (dp[finish.first][finish.second] == 0) {
		cout << "NO";
		return 0;
	}
 
	cout << "YES\n" << dp[finish.first][finish.second]-1 << "\n";
 
	x = finish.first;
	y = finish.second;
 
	vector<string> route;
 
	while (dp[x][y] != 1) {
		if (x - 1 >= 0 && dp[x - 1][y] == dp[x][y] - 1) {
			route.push_back("D");
			x--;
			continue;
		}
		if (x + 1 < n && dp[x + 1][y] == dp[x][y] - 1) {
			route.push_back("U");
			x++;
			continue;
		}if (y - 1 >= 0 && dp[x][y - 1] == dp[x][y] - 1) {
			route.push_back("R");
			y--;
			continue;
		}
		if (y + 1 < m && dp[x][y+1] == dp[x][y] - 1) {
			route.push_back("L");
			y++;
			continue;
		}
	}
 
	while (route.size()) {
		cout << route.back();
		route.pop_back();
	}
 
	return 0;
}