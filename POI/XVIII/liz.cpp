#include <iostream>
#include <map>

using namespace std;

struct LIZ {
	int n;
	int* odp2;
	bool* liz;

	void setup() {
		int q;
		cin >> n >> q;
		int min = -1;
		int max = -1;
		int sum = 0;
		liz = new bool[n] { 0 };
		odp2 = new int [n * 4]{ 0 };

		char a;
		for (int i = 0; i < n; i++) {
			cin >> a;
			if (a == 'T') {
				sum += 2;
				liz[i] = 1;
			}
			else {
				if (min == -1) min = i;
				max = i;
				sum++;
			}
		}

		fillWithAnsw(sum, min, max);
		int b;
		for (int i = 0; i < q; i++) {
			cin >> b;
			if (odp2[b*2]==0) cout << "NIE\n";
			else cout << odp2[b*2] << " " << odp2[b*2+1] << "\n";
		}
	}

	void fillWithAnsw(int sum, int min, int max) {
		int tSum = sum;
		int bot = 0;
		int top = n - 1;
		odp2[tSum * 2] = bot + 1;
		odp2[tSum * 2 + 1] = top + 1;
		while (tSum > 0) {
			if (liz[bot]) {
				bot++;
			}
			else if (liz[top]) {
				top--;
			}
			else {
				bot++;
				top--;
			}
			tSum -= 2;
			odp2[tSum * 2] = bot + 1;
			odp2[tSum * 2 + 1] = top + 1;
		}

		bot = 0;
		top = n - 1;
		tSum = sum;
		if (min == -1) return;
		if (top - min >= max) {
			bot = min+1;
			for (int i = 0; i < bot; i++) tSum -= ((int)liz[i] + 1);
		}
		else {
			top = max - 1;
			for (int i = n-1; i >= max; i--) tSum -= ((int)liz[i] + 1);
		}
		if (tSum == 0) return;
		odp2[tSum * 2] = bot + 1;
		odp2[tSum * 2 + 1] = top + 1;
		while (tSum > 0) {
			if (liz[bot]) {
				bot++;
			}
			else if (liz[top]) {
				top--;
			}
			else {
				bot++;
				top--;
			}
			tSum -= 2;
			odp2[tSum*2] = bot + 1;
			odp2[tSum * 2 + 1] = top + 1;
		}
	}
}liz;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	liz.setup();

	return 0;
}