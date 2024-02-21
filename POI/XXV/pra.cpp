#include <iostream>
#include <set>
#include <map>
#include <queue>

#define mld 1000000000

using namespace std;

struct PRA {
	int n, k;
	int** times;
	priority_queue<pair<int,pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > startTimes;

	void setup() {
		cin >> n >> k;

		times = new int*[n];
		int a, b;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			startTimes.push(make_pair(a,make_pair(b,i)));
			times[i] = new int[2]{ a,b };
		}
	}

	void getAnsw() {
		set<pair<int, pair<int, int>>> ends;

		int tmp = 0;
		int start = 0;
		for (int i = 0; i < k; i++) {
			start = startTimes.top().first;
			tmp = startTimes.top().second.first;
			ends.insert(make_pair(tmp, make_pair(start, startTimes.top().second.second)));
			startTimes.pop();
		}
		int maxTime = (* ends.begin()).first - start;

		int* bestGap = new int[2]{ start, (*ends.begin()).first };
		int tmpTime = 0;
		long long toDelete = 0;
		for (int i = k; i < n; i++) {
			start = startTimes.top().first;
			tmp = startTimes.top().second.first;

			if (tmp > (* ends.begin()).first) {

				toDelete = (long long)((*ends.begin()).second.first)*mld+(*ends.begin()).first;
				ends.erase(*ends.begin());
				ends.insert(make_pair(tmp, make_pair(start, startTimes.top().second.second)));
				tmpTime = (* ends.begin()).first - start;
				if (tmpTime > maxTime) {
					maxTime = tmpTime;
					bestGap[0] = start;
					bestGap[1] = (*ends.begin()).first;
				}

			}
			startTimes.pop();
		}
		vector<int> ids;

		for (int i = 0; i < n; i++) {
			if (ids.size() == k)
				break;
			if (times[i][0] <= bestGap[0] && times[i][1] >= bestGap[1])
				ids.push_back(i + 1);
		}
		cout << maxTime<<endl;
		for (int i = 0; i < k; i++) {
			cout << ids[i] << " ";
		}
	}
}pra;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	pra.setup();
	pra.getAnsw();

	return 0;
}