#include <iostream>
#include <queue>
#include <map>

using namespace std;

#define mod 1000000007

int NWD(int a, int b) {
	if (b < a) {
		int tmp = b;
		b = a;
		a = tmp;
	}

	int max = 1;
	if (b % a == 0) return a;
	for (int i = 2; i * i <= a; i++) {
		if (a % i == 0 && b % i == 0)
			max = ((max>i)?max:i);
		int tmp = a / i;
		if (a % tmp == 0 && b % tmp == 0)
			max = ((max > tmp) ? max : tmp);
	}

	return max;
}

long long getNewtons(int a, int b) {
	vector<int> toCheck;
	long long out = 1;
	if (a - b > b) b = a - b;
	for (int i = 2; i <= a - b; i++) {
		toCheck.push_back(i);
	}

	int tmp = 0;
	int tmp2 = 0;
	for (int i = b + 1; i <= a; i++) {
		tmp = i;
		for (int j = 0; j < toCheck.size(); j++) {
			tmp2 = NWD(tmp, toCheck[j]);
			if (tmp == 1) break;
			if (tmp2 > 1) {
				tmp /= tmp2;
				toCheck[j] /= tmp2;
			}
		}
		out *= tmp;
		out %= mod;
	}
	return out;
}

int main() {
	int t;
	cin >> t;
	int n, k;
	priority_queue<int> a;
	map<int, int> quantity;
	int kth = -1;
	int nok = -1;
	int tmp;

	for (int i = 0; i < t; i++) {
		quantity.clear();
		cin >> n >> k;
		kth = -1;
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			a.push(tmp);
		}

		int l = 1;
		int last = -1;
		while (a.size()) {
			if(kth==-1)
				if (last != a.top()) {
					nok = 1;
					last = a.top();
				}
				else
					nok++;
			if (l == k)
				kth = a.top();
			if (quantity.find(a.top()) == quantity.end())
				quantity[a.top()] = 0;
			quantity[a.top()]++;
			a.pop();
			l++;
		}

		cout << getNewtons(quantity[kth], nok)<<endl;
	}

	return 0;
}