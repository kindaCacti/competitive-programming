#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct SCCnode {
	vector<int> edges;
	int consistsOf = 0;
	int canGoTo = 0;
};

struct DRO {
	int n;
	vector<int>* ways;
	vector<int>* rWays;
	vector<SCCnode> nodes;
	int* connectsToNode;
	void setup() {
		cin >> n;
		int a, b, nd;
		cin >> nd;
		ways = new vector<int>[n];
		rWays = new vector<int>[n];
		for (int i = 0; i < nd; i++) {
			cin >> a >> b;
			ways[a - 1].push_back(b - 1);
			rWays[b - 1].push_back(a - 1);
		}
		setSCC();
	}

	void setSCC() {
		vector<int> nodeQueue;
		vector<int> queue;
		bool* visited = new bool[n]{0};

		int k = 0;
		while (k<n) {
			while (k < n && visited[k])k++;

			if (k == n) break;
			visited[k] = true;
			queue = { k };

			while (queue.size()) {
				int currentNode = queue.back();

				bool hasNeighbours = false;
				for (int i = 0; i < ways[currentNode].size(); i++) {
					int tmp = ways[currentNode][i];
					if (!visited[tmp]) {
						visited[tmp] = true;
						queue.push_back(tmp);
						hasNeighbours = true;
					}
				}

				if (!hasNeighbours) {
					nodeQueue.push_back(queue.back());
					queue.pop_back();
				}
			}
		}

		k = n-1;
		int it = 0;
		connectsToNode = new int[n] {0};
		visited = new bool[n] {0};
		while (k>=0) {
			nodes.push_back(SCCnode());
			while (k >=0 && visited[nodeQueue[k]]) k--;
			if (k < 0) break;
			queue = { nodeQueue[k] };
			visited[nodeQueue[k]] = true;
			while (queue.size()) {
				int currentNode = queue.back();
				queue.pop_back();
				bool hasNeighbour = false;
				for (int i = 0; i < rWays[currentNode].size(); i++) {
					int tmp = rWays[currentNode][i];
					if (!visited[tmp]) {
						hasNeighbour = true;
						queue.push_back(tmp);
						visited[tmp] = true;
					}
				}
				nodes.back().consistsOf++;
				connectsToNode[currentNode] = it;
			}
			it++;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < ways[i].size(); j++) {
				if (connectsToNode[i] != connectsToNode[ways[i][j]]) {
					nodes[connectsToNode[i]].edges.push_back(connectsToNode[ways[i][j]]);
				}
			}
		}
	}

	void getAnsw() {
		for (int i = nodes.size() - 1; i >= 0; i--) {
			int tmp = 0;
			for (int j = 0; j < nodes[i].edges.size(); j++) {
				tmp += nodes[nodes[i].edges[j]].canGoTo;
			}
			nodes[i].canGoTo = tmp + nodes[i].consistsOf;
		}

		for (int i = 0; i < n; i++) {
			cout<<nodes[connectsToNode[i]].canGoTo-1<<"\n";
		}
	}
} dro;

int main() {
	dro.setup();
	dro.getAnsw();

	return 0;
}