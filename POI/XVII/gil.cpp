#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct CITY {
	vector<int> neighbours;
	int num = -1;
};

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int nm, nd;
	cin >> nm >> nd;

	CITY* cities = new CITY[nm];
	int a, b;
	int nUsed = 0;
	set<int> unvisited;

	for (int i = 0; i < nm; i++) unvisited.insert(i);
	for (int i = 0; i < nd; i++) {
		cin >> a >> b;
		a--;
		b--;

		cities[a].neighbours.push_back(b);
		cities[b].neighbours.push_back(a);
	}

	while (unvisited.size()) {
		vector<int> queue = { *unvisited.begin() };
		int j = 0;
		cities[queue.back()].num = 0;
		while (j < queue.size()) {
			unvisited.erase(queue[j]);
			for (int i = 0; i < cities[queue[j]].neighbours.size(); i++) {
				if (cities[cities[queue[j]].neighbours[i]].num==-1) {
					queue.push_back(cities[queue[j]].neighbours[i]);
					cities[cities[queue[j]].neighbours[i]].num = (cities[queue[j]].num + 1) % 2;
				}
			}
			if (j == 0 && queue.size() == 1) {
				cout << "NIE";
				return 0;
			}
			j++;
		}
	}

	cout << "TAK\n";
	for (int i = 0; i < nm; i++) cout << ((cities[i].num%2)?"S" : "K") << "\n";

	return 0;
}