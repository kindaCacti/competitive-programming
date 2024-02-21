#include <iostream>
#include <map>
#include <queue>

using namespace std;

map<int, long long> mem;
map<int, long long> amountOfValues;

long long getMax(int* values, int size, int i = 0) {
	if (i == size)
		return 0;
	if (i == size - 1)
		return values[i] * amountOfValues[values[i]];
	if (mem.find(i) != mem.end())
		return mem[i];



	if (i < size - 1) {
		if (values[i] - 1 == values[i + 1]) {
			long long tmp1 = getMax(values, size, i + 1);
			long long tmp2 = getMax(values, size, i + 2) + values[i] * amountOfValues[values[i]];

			if (tmp1 < tmp2)
				tmp1 = tmp2;
			mem[i] = tmp1;
		}
		else {
			mem[i] = getMax(values, size, i + 1) + values[i] * amountOfValues[values[i]];
		}
	}

	return mem[i];
}

int main() {
	int n;
	cin >> n;
	//int* values = new int[n];

	int a;
	priority_queue<int> values;

	for (int i = 0; i < n; i++) {
		cin >> a;
		if (amountOfValues.find(a) == amountOfValues.end())
			amountOfValues[a] = 0;
		amountOfValues[a]++;
		values.push(a);
	}

	int* vals = new int[amountOfValues.size()];

	int tmp = -1;
	int i = 0;
	while (values.size()) {
		vals[i] = values.top();
		i++;
		tmp = values.top();
		while (values.size() && values.top() == tmp)
			values.pop();
	}

	cout << getMax(vals, amountOfValues.size());

}