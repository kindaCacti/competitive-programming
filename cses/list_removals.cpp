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
			vals[p] = vals[p * 2] + vals[p * 2 + 1];
		} while (p != 0);
	}
 
	void build(int*& pvals, int n, int s = SIZE) {
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
	int n;
	cin >> n;
 
	int* vals = new int[n];
	int* vals2 = new int[n];
 
	for (int i = 0; i < n; i++) {
		cin >> vals[i];
		vals2[i] = 1;
	}
 
	TREE t;
	t.build(vals2, n, n + 1);
 
	int min = 0;
	int max = n; 
	int mid;
 
	int tmp = 0;
	int tmp2, a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		min = 0;
		max = n-1;
		tmp = 0;
		while (min < max) {
			mid = ((max - min) / 2) + min;
			tmp2 = t.getAnsw(min, mid);
			if (tmp + tmp2 >= a) {
				max = mid;
			}
			else {
				min = mid + 1;
				tmp += tmp2;
			}
		}
 
		cout << vals[min] << endl;
		t.chVal(min, 0);
	}
}