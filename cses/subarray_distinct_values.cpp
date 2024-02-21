#include <iostream>
#include <map>
#include <queue>
 
using namespace std;
 
int main() {
	map<int, int> vals;
	int n, k;
	cin >> n >> k;
 
	long long out = 0;
	int a;
	queue<int> pastVals;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> a;
		pastVals.push(a);
		vals[a]++;
		while (vals.size() > k) {
			tmp = pastVals.front();
			pastVals.pop();
			vals[tmp]--;
			if (vals[tmp] == 0) {
				vals.erase(tmp);
			}
		}
		out += pastVals.size();
	}
 
	cout << out;
}