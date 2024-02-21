#include <iostream>
#include <cmath>
 
using namespace std;
 
const int SIZE = 131072; //2^17
 
struct TREE {
	long long* vals;
	int size;
 
	void chVal(int p, int nv) {
		p += size;
		vals[p] = nv;
 
		int tmp = 0;
		do {
			p /= 2;
			vals[p] = vals[p * 2]+vals[p * 2 + 1];
		} while (p != 0);
	}
 
	void build(int* &pvals, int n, int s = SIZE) {
		vals = new long long[s * 2];
		fill(vals, vals + s * 2, 0);
		size = s;
 
		for (int i = 0; i < n; i++) {
			chVal(i, pvals[i]);
		}
	}
 
	long long getAnsw(int a, int b) {
		a += size;
		b += size;
		int tmp = a;
		int pos = a;
		int add = 1;
		long long out = 0;
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
			out += vals[tmp];
			a += add;
		}
 
		return out;
	}
};
 
int main() {
	int n, q;
	cin >> n >> q;
 
	int* vals = new int[n];
 
	for (int i = 0; i < n; i++) {
		cin >> vals[i];
	}
 
	TREE t;
	t.build(vals, n, n+1);
 
	int o, a, b;
	while (q--) {
		cin >> o >> a >> b;
		if (o == 1) {
			a--;
			t.chVal(a, b);
		}
		if (o == 2) {
			a--; b--;
			cout << t.getAnsw(a, b) << endl;
		}
	}
}