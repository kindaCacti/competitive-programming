#include <iostream>

using namespace std;

bool isPrime(int a) {
	for (int i = 2; i * i <= a; i++) {
		if (a % i == 0)
			return false;
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	if (n == 2)
		cout << 1;
	else if (n % 2 == 0)
		cout << 2;
	else if (isPrime(n))
		cout << 1;
	else if (isPrime(n - 2))
		cout << 2;
	else
		cout << 3;
}