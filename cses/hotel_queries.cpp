#include <iostream>
#include <cmath>
 
using namespace std;
 
const int SIZE = 131072; //2^17
 
struct TREE {
	int* vals;
	int size;
 
	void chVal(int p, int nv) {
		p += size;
		vals[p] = nv;
 
		int tmp = 0;
		do {
			p /= 2;
			vals[p] = max(vals[p * 2], vals[p * 2 + 1]);
		} while (p != 0);
	}
 
	void build(int*& pvals, int n, int s = SIZE) {
		vals = new int[s * 2];
		fill(vals, vals + s * 2, 0);
		size = s;
 
		for (int i = 0; i < n; i++) {
			chVal(i, pvals[i]);
		}
	}
 
	int getAnsw(int a, int b) {
		a += size;
		b += size;
		int tmp = a;
		int pos = a;
		int add = 1;
		int out = vals[a];
		while (a <= b) {
			add = 1;
			tmp = a;
			while (add * 2 + a < b) {
				add *= 2;
				pos = tmp / 2;
				if (pos * add < a) {
					add /= 2;
					break;
				}
				tmp /= 2;
			}
			out = max(out, vals[tmp]);
			a += add;
		}
 
		return out;
	}
};
 
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	int n, q;
	cin >> n >> q;
 
	int* vals = new int[n];
 
	for (int i = 0; i < n; i++) {
		cin >> vals[i];
	}
 
	TREE t;
	t.build(vals, n, n + 1);
 
	int a;
	while (q--) {
		cin >> a;
 
		if (t.getAnsw(0, n - 1) < a) {
			cout << 0 << endl;
			continue;
		}
 
		int min = 0;
		int max = n;
		int mid;
 
		while (min < max) {
			mid = ((max - min) / 2) + min;
			if (t.getAnsw(min, mid) >= a) max = mid;
			else min = mid + 1;
		}
 
		t.chVal(min, t.getAnsw(min, min) - a);
		cout << min + 1<<endl;
	}
}
