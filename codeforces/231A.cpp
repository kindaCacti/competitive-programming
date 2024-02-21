#include <iostream>
#include <queue>
 
using namespace std;
 
int main() {
	int out = 0;
	bool a, b, c;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		if ((int)a + (int)b + (int)c >= 2)
			out++;
	}
	cout << out;
	
}