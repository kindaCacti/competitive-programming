#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define mod 1000000007;

map<pair<int, bool>, int> values;

int getAmmount(int n, int sum, int min, int max, bool doneMin = false) {
	if (sum == max && doneMin) 
		return 1;
	if (sum > max || (sum==max && !doneMin))
		return 0;
	if (values.find(make_pair(sum, doneMin)) != values.end())
		return values[make_pair(sum, doneMin)];

	int csum = 0;
	for (int i = 1; i <= n && i <= max-sum; i++) {
		csum += getAmmount(n, sum + i, min, max, ((i>=min||doneMin)?true:false));
		csum %= mod;
	}

	values[make_pair(sum, doneMin)] = csum;
	return csum;
}

int main() {
	int n, k, d;
	cin >> k >> n >> d;

	cout << getAmmount(n, 0, d, k);
	int i = 1;
	return 0;
}