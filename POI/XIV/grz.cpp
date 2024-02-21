#include <iostream>
#include <vector>

using namespace std;

struct GROUP {
	bool isHigh = true;
	bool isSmall = true;
};

struct GID {
	int n;
	int** map;
	int** isPartOf;
	vector<GROUP> groups;

	void setup() {
		cin >> n;
		map = new int* [n];
		isPartOf = new int*[n];

		for (int i = 0; i < n; i++) {
			map[i] = new int[n];
			isPartOf[i] = new int[n]{0};
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}
		check();
	}

	void setParts(int x, int y, int gr) {

		vector<int*> queue = { new int[2]{x,y} };
		int k = 0;

		while (k < queue.size()) {
			x = queue[k][0];
			y = queue[k][1];
			for (int i = x - 1; i <= x + 1; i++) {
				if (i < 0 || i >= n) continue;
				for (int j = y - 1; j <= y + 1; j++) {
					if (j < 0 || j >= n) continue;
					if (i == x && j == y) continue;

					if (map[j][i] == map[y][x]) {
						if (isPartOf[j][i] != 0) continue;

						isPartOf[j][i] = groups.size();
						queue.push_back(new int[2]{ i,j });
						continue;
					}

					if (map[j][i] < map[y][x]) groups.back().isSmall = false;
					if (map[j][i] > map[y][x]) groups.back().isHigh = false;
				}
			}


			k++;
		}
	}

	void check() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (isPartOf[i][j] == 0) {
					groups.push_back(GROUP());
					setParts(j, i, groups.size());
				}
			}
		}
	}

	int* getAnsw() {
		int high = 0, low = 0;
		for (int i = 0; i < groups.size(); i++) {
			if (groups[i].isHigh) high++;
			if (groups[i].isSmall) low++;
		}

		return new int[2]{ high, low };
	}

} gid;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	gid.setup();
	int* tmp = gid.getAnsw();
	cout << tmp[0] << " " << tmp[1];

	return 0;
}