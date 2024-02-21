#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
	int n;
	cin >> n;
 
	bool* used = new bool[n] {0};
	int done = 0;
	vector<int> tab;
	int p = 0;
	while (done < n) {
		tab.clear();
		for (int i = 0; i < n; i++) {
			if (used[i]) continue;
 
			tab.push_back(i + 1);
		}
 
		for (int i = 0; i < tab.size(); i++) {
			p++;
			if (p % 2) {
				continue;
			}
 
			used[tab[i]-1] = 1;
			cout << tab[i] << " ";
			done++;
		}
	}
	
	return 0;
}
