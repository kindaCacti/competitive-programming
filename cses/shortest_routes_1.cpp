#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
int main() {
    int n, m;
    cin >> n >> m;
 
    vector<pair<int, int>>* edges = new vector<pair<int, int>>[n];
 
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        a--; b--;
        edges[a].push_back({ b,c });
    }
 
    long long* nums = new long long[n] {0};
    nums[0] = 1;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> nextPoints;
    nextPoints.push({ 1,0 });
    pair<long long, long long> tmp;
    while (nextPoints.size()) {
        tmp = nextPoints.top();
        nextPoints.pop();
        if (nums[tmp.second] != 0 && nums[tmp.second] < tmp.first) {
            continue;
        }
 
        nums[tmp.second] = tmp.first;
 
        for (pair<int, int> nn : edges[tmp.second]) {
            nextPoints.push({ nums[tmp.second] + nn.second, nn.first });
        }
    }
 
    for (int i = 0; i < n; i++) {
        cout << nums[i] - 1 << " ";
    }
    return 0;
}