#include <iostream>
#include <queue>
#include <map>
 
using namespace std;
 
int main() {
	int n;
	cin >> n;
 
	vector<pair<int, int>> ranges;
	priority_queue< pair<int, int>, vector< pair<int, int>>, greater< pair<int, int>>> rs;
	priority_queue< pair<int, int>, vector< pair<int, int>>, greater< pair<int, int>>> rs2;
	priority_queue< pair<int, int>, vector< pair<int, int>>, greater< pair<int, int>>> starts;
 
	map<pair<int, int>, pair<bool, bool>> poss;
 
	int a, b;
	int bend = -1;//best end
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		poss[{a, b}] = { 0,0 };
		starts.push({ a,b });
		rs2.push({ b,a });
		rs.push({ a,-b });
		ranges.push_back({ a,b });
	}
 
	pair<int, int> tmp;
	while(rs.size()){
		tmp = rs.top();
		tmp.second = -tmp.second;
		rs.pop();
		if (tmp.second <= bend) {
			poss[tmp].second = 1;
		}
		else {
			bend = tmp.second;
		}
	}
 
	while (starts.size()) {
		tmp = starts.top();
		starts.pop();
		while (rs2.size()&&(rs2.top().second < tmp.first||(rs2.top().second==tmp.first&&rs2.top().first==tmp.second))) {
			rs2.pop();
		}
		if (rs2.size()&&tmp.second >= rs2.top().first) {
			poss[tmp].first = 1;
			
		}
		rs2.push({ tmp.second, tmp.first });
	}
 
	for (int i = 0; i < n; i++) {
		cout << poss[ranges[i]].first << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << poss[ranges[i]].second << " ";
	}
 
	return 0;
}