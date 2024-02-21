#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
 
	bool** walls = new bool* [n];
	int** answ = new int* [n];
	char a;
	pair<int, int> start, finish;
	int** closestMonster = new int* [n];
	vector<pair<int, int>> monsters;
	vector<pair<int, int>> exits;
 
	for (int i = 0; i < n; i++) {
		walls[i] = new bool[m] {0};
		closestMonster[i] = new int [m] {0};
		answ[i] = new int[m] {0};
		for (int j = 0; j < m; j++) {
			cin >> a;
			if (a == '#') {
				walls[i][j] = 1;
			}
			if (a == 'A') {
				start = { i,j };
			}
			if (a == 'B') {
				finish = { i,j };
			}
			if (a == 'M') {
				monsters.push_back({ i,j });
				closestMonster[i][j] = 1;
			}
			if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && a != '#') {
				exits.push_back({ i,j });
			}
		}
	}
 
	int k = 0;
	vector<pair<int, int>> queue = vector<pair<int, int>>(monsters);
	pair<int, int> cp;
	while (k < queue.size()) {
		cp = queue[k];
		if (cp.first > 0 && closestMonster[cp.first - 1][cp.second] == 0 && !walls[cp.first - 1][cp.second]) {
			closestMonster[cp.first - 1][cp.second] = closestMonster[cp.first][cp.second] + 1;
			queue.push_back({ cp.first - 1, cp.second });
		}
		if (cp.first < n - 1 && closestMonster[cp.first + 1][cp.second] == 0 && !walls[cp.first + 1][cp.second]) {
			closestMonster[cp.first + 1][cp.second] = closestMonster[cp.first][cp.second] + 1;
			queue.push_back({ cp.first + 1, cp.second });
		}
		if (cp.second > 0 && closestMonster[cp.first][cp.second - 1] == 0 && !walls[cp.first][cp.second - 1]) {
			closestMonster[cp.first][cp.second - 1] = closestMonster[cp.first][cp.second] + 1;
			queue.push_back({ cp.first, cp.second - 1 });
		}
		if (cp.second < m - 1 && closestMonster[cp.first][cp.second + 1] == 0 && !walls[cp.first][cp.second + 1]) {
			closestMonster[cp.first][cp.second + 1] = closestMonster[cp.first][cp.second] + 1;
			queue.push_back({ cp.first, cp.second + 1 });
		}
		k++;
	}
 
	queue.clear();
	k = 0;
 
	answ[start.first][start.second] = 1;
	queue.push_back(start);
 
	while (k < queue.size()) {
		cp = queue[k];
		if (cp.first > 0 && answ[cp.first - 1][cp.second] == 0 && !walls[cp.first - 1][cp.second]) {
			answ[cp.first - 1][cp.second] = answ[cp.first][cp.second] + 1;
			queue.push_back({ cp.first - 1, cp.second });
		}
		if (cp.first < n - 1 && answ[cp.first + 1][cp.second] == 0 && !walls[cp.first + 1][cp.second]) {
			answ[cp.first + 1][cp.second] = answ[cp.first][cp.second] + 1;
			queue.push_back({ cp.first + 1, cp.second });
		}
		if (cp.second > 0 && answ[cp.first][cp.second - 1] == 0 && !walls[cp.first][cp.second - 1]) {
			answ[cp.first][cp.second - 1] = answ[cp.first][cp.second] + 1;
			queue.push_back({ cp.first, cp.second - 1 });
		}
		if (cp.second < m - 1 && answ[cp.first][cp.second + 1] == 0 && !walls[cp.first][cp.second + 1]) {
			answ[cp.first][cp.second + 1] = answ[cp.first][cp.second] + 1;
			queue.push_back({ cp.first, cp.second + 1 });
		}
		k++;
	}
 
	bool done = false;
	for (pair<int, int> np : exits) {
		if (closestMonster[np.first][np.second] > answ[np.first][np.second] || (closestMonster[np.first][np.second] == 0 && answ[np.first][np.second] != 0)) {
			finish = np;
			cout << "YES\n";
			done = true;
			break;
		}
	}
 
	if (!done) {
		cout << "NO\n";
		return 0;
	}
 
	vector<string> route;
	cp = finish;
 
	while (answ[cp.first][cp.second] != 1) {
		if (cp.first > 0 && answ[cp.first - 1][cp.second] + 1 == answ[cp.first][cp.second]) {
			route.push_back("D");
			cp.first--;
			continue;
		}
		if (cp.first < n - 1 && answ[cp.first + 1][cp.second] + 1 == answ[cp.first][cp.second]) {
			route.push_back("U");
			cp.first++;
			continue;
		}
		if (cp.second > 0 && answ[cp.first][cp.second - 1] + 1 == answ[cp.first][cp.second]) {
			route.push_back("R");
			cp.second--;
			continue;
		}
		if (cp.second < m - 1 && answ[cp.first][cp.second + 1] + 1 == answ[cp.first][cp.second]) {
			route.push_back("L");
			cp.second++;
			continue;
		}
	}
 
	cout << route.size() << "\n";
 
	for (int i = route.size() - 1; i >= 0; i--) {
		cout << route[i];
	}
 
	return 0;
}