#include <iostream>
 
using namespace std;
 
const int SIZE = 262144;
 
struct TREE {
	int size;
	long long* vals;
 
	void setup(int*& svals, int n, int s = SIZE) {
		size = s;
		vals = new long long [size * 2] {0};
 
		for (int i = 0; i < n; i++) {
			vals[i + size] = svals[i];
		}
	}
 
	void updateVal(int a, int b, int v) {
		a += size;
		b += size;
 
		int tmp, add, tmps;
		while (a <= b) {
			tmp = a;
			add = 1;
			while (add * 2 + a < b) {
				add *= 2;
				tmps = tmp / 2;
				if (tmps * add < a) {
					add /= 2;
					break;
				}
				tmp = tmps;
			}
			vals[tmp] += v;
			a += add;
		}
	}
 
	long long getVal(int a) {
		a += size;
		long long out = 0;
		while (a) {
			out += vals[a];
			a /= 2;
		}
 
		return out;
	}
};
 
int main() {
	int n, q;
	cin >> n >> q;
 
	int* vals = new int[n] {0};
	for (int i = 0; i < n; i++) {
		cin >> vals[i];
	}
 
	TREE t;
	t.setup(vals, n);
	
	int o, k, a, b;
	while (q--) {
		cin >> o;
		if (o == 1) {
			cin >> a >> b >> k;
			a--; b--;
			t.updateVal(a, b, k);
		}
		else {
			cin >> k;
			k--;
			cout << t.getVal(k)<<endl;
		}
	}
 
	return 0;
}
