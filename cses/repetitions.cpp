#include <iostream>
 
using namespace std;
 
int main() {
 
	string a;
	cin >> a;
 
	int cn = 1;
	int max = 1;
	for (int i = 1; i < a.size(); i++) {
		if (a[i - 1] == a[i]) {
			cn++;
		}
		else {
			cn = 1;
		}
 
		if (cn > max) max = cn;
	}
 
	cout << max;
