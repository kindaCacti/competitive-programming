#include <iostream>
 
using namespace std;
 
const int mod = 1000000007;
 
long long pow(long long a, long long b) {
	if (b == 0) return 1;
 
	long long tmp = pow(a, b / 2);
	tmp *= tmp;
	tmp %= mod;
	if (b % 2) {
		tmp *= a;
		tmp %= mod;
	}
 
	return tmp;
}
 
int main() {
	int n;
	cin >> n;
 
	long long a, b;
	while (n--) {
		cin >> a >> b;
		cout<<pow(a, b)<<"\n";
	}
 
	return 0;
}
