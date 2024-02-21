#include <iostream>
#include <queue>
 
using namespace std;
 
int main() {
	int n;
	cin >> n;
 
	priority_queue<pair<int, int>> vals;
	vector<int> input;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		input.push_back(a);
	}
 
	int* output = new int[n] {0};
 
	int tmp;
	while (input.size()) {
		tmp = input.back();
		while (vals.size()&&vals.top().first > tmp) {
			output[vals.top().second-1] = input.size();
			vals.pop();
		}
		vals.push({ tmp, input.size() });
		input.pop_back();
	}
 
	for (int i = 0; i < n; i++) {
		cout << output[i] << " ";
	}
 
	return 0;
}