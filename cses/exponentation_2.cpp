#include <iostream>
 
using namespace std;
 
long long pow(long long a, long long b, int mod) {
	if (b == 0) return 1;
 
	long long tmp = pow(a, b / 2, mod);
	tmp *= tmp;
	tmp %= mod;
	if (b % 2) {
		tmp *= a;
		tmp %= mod;
	}
 
	return tmp;
}
 
int main() {
	const int mod = 1000000007;
	int n;
	cin >> n;
 
	long long a, b,c;
	while (n--) {
		cin >> a >> b >> c;
		cout<<pow(a,pow(b, c, mod-1), mod)<<"\n";
	}
 
	return 0;
}
