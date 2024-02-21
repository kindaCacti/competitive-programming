#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    int n, m;
    cin >> n >> m;
 
    vector<int>* edges = new vector<int>[n];
    int a, b;
 
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--; b--;
 
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
 
    int* numbering = new int[n] {0};
 
    int k = 0;
    vector<int> queue;
 
    int cn;
    for (; k < n; k++) {
        if (numbering[k]) continue;
 
        queue = { k };
        numbering[k] = 1;
        for (int i = 0; i < queue.size(); i++) {
            cn = queue[i];
 
            for (int nn : edges[cn]) {
                if (numbering[nn]) continue;
                numbering[nn] = numbering[cn] + 1;
                queue.push_back(nn);
            }
        }
    }
 
    int starting = -1;
    pair<int, int> next1, next2;
    int tmp;
    for (int i = 0; i < n; i++) {
        tmp = 0;
 
        for (int nn : edges[i]) {
            if (numbering[nn] <= numbering[i]) {
                if (tmp == 0) {
                    next1 = { nn, numbering[nn] };
                }
                else {
                    next2 = { nn, numbering[nn] };
                }
                tmp++;
            }
        }
 
        if (tmp > 1) {
            starting = i;
            break;
        }
    }
 
    vector<int> route1 = {starting+1}, route2 = {starting+1};
    if (starting != -1) {
        if (next1.second < next2.second) {
            route2.push_back(next2.first + 1);
            for (int nn : edges[next2.first]) {
                if (numbering[nn] < next2.second) {
                    next2 = { nn, numbering[nn] };
                }
            }
        }
        else if (next1.second > next2.second) {
            route1.push_back(next1.first + 1);
            for (int nn : edges[next1.first]) {
                if (numbering[nn] < next1.second) {
                    next1 = { nn, numbering[nn] };
                }
            }
        }
 
        while (next1.first != next2.first) {
            route1.push_back(next1.first + 1);
            route2.push_back(next2.first + 1);
 
            for (int nn : edges[next1.first]) {
                if (numbering[nn] < next1.second) {
                    next1 = { nn, numbering[nn] };
                }
            }
 
            for (int nn : edges[next2.first]) {
                if (numbering[nn] < next2.second) {
                    next2 = { nn, numbering[nn] };
                }
            }
        }
 
        route1.push_back(next1.first+1);
 
        cout << route1.size() + route2.size() << "\n";
 
        for (int mv : route1) {
            cout << mv << " ";
        }
 
        for (int i = route2.size() - 1; i >= 0; i--) {
            cout << route2[i] << " ";
        }
    }
    else {
        cout << "IMPOSSIBLE";
    }
 
    return 0;
}