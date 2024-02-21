#include <iostream>
#include <map>

using namespace std;

map<int, int> mem;

int fall(pair<int, int>* trees, int size, int max, int i = 0) {
	if (i == size)
		return 0;
	if (mem.find(i) != mem.end())
		return mem[i];

	if (i == 0) {
		return (fall(trees, size, max, 1) + 1);
	}
	if (i == size - 1) {
		return 1;
	}
	int out = 0;
	int tmp;

	if (max < trees[i].first-trees[i].second) {
		tmp = fall(trees, size, trees[i].first, i + 1) + 1;
		if (tmp > out)
			out = tmp;
	}

	if (trees[i + 1].first > trees[i].first + trees[i].second) {
		tmp = fall(trees, size, trees[i].first + trees[i].second, i + 1) + 1;
		if (tmp > out)
			out = tmp;
	}
	
	tmp = fall(trees, size, trees[i].first, i + 1);
	if (tmp > out)
		out = tmp;

	mem[i] = out;
	return out;
}

int main() {
	int n;
	cin >> n;

	pair<int, int>* trees = new pair<int, int>[n];
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		trees[i] = make_pair(a, b);
	}
	cout << fall(trees, n, trees[0].first);
}