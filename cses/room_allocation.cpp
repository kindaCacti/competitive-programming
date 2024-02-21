#include <iostream>
#include <queue>
#include <map>
 
using namespace std;
 
int main() {
	int n;
	cin >> n;
 
	int a, b;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> ranges;
	vector<pair<int, int>> inputs;
	map<pair<int, int>, vector<int>> rooms;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		inputs.push_back({ a,b });
		ranges.push({ a,b });
	}
 
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> leaves;
	vector<int> freeRooms;
 
	int out = 0;
	while (ranges.size()) {
		if (leaves.size()==0||ranges.top().first <= leaves.top().first) {
			if (leaves.size()+1 > out) {
				leaves.push({ ranges.top().second, leaves.size()+1 });
				rooms[ranges.top()].push_back(leaves.size());
				out = leaves.size();
			}
			else {
				leaves.push({ ranges.top().second, freeRooms.back() });
				rooms[ranges.top()].push_back(freeRooms.back());
				freeRooms.pop_back();
			}
			ranges.pop();
		}
		else {
			freeRooms.push_back(leaves.top().second);
			leaves.pop();
		}
	}
 
	cout << out << endl;
 
	for (int i = 0; i < n; i++) {
		cout << rooms[inputs[i]].back() << " ";
		rooms[inputs[i]].pop_back();
	}
 
	return 0;
}