#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	unsigned int* heights = new unsigned int[n];

	int a;
	for (int i = 0; i < n; i++) {
		cin >>a>> heights[i];
	}

	int last = heights[0];
	int num = 1;
	vector<unsigned int> heightsQueue = { heights[0] };
	for (int i = 1; i < n; i++) {
		if (heightsQueue.size()==0||heights[i] > last) {
			num++;
			heightsQueue.push_back(heights[i]);
		}
		else if (heights[i] < last) {
			while (heightsQueue.size()&&heightsQueue.back() > heights[i]) heightsQueue.pop_back();

			if (heightsQueue.size()==0||heightsQueue.back() < heights[i]) {
				num++;
				heightsQueue.push_back(heights[i]);
			}
		}
		last = heights[i];
	}

	cout << num;
	return 0;
}