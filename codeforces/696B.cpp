#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> edges;
vector<int> below, parent;
vector<double> ev;

int dfs(int s = 0){
    int tmp = 0;
    for(int ne : edges[s]){
        tmp += dfs(ne);
    }
    tmp++;
    below[s] = tmp;
    return tmp;
}

int main(){
    int n;
    cin>>n;
    int a;
    edges.assign(n, {});
    below.assign(n, 0);
    parent.assign(n, -1);
    ev.assign(n, 0);
    ev[0] = 1;
    for(int i = 1; i<n; i++){
        cin>>a;
        a--;
        edges[a].push_back(i);
        parent[i] = a;
    }

    dfs();

    double tmp;
    int t2;
    for(int i = 1; i<n; i++){
        tmp = ev[parent[i]];
        //cout<<ev[parent[i]]<<" "<<below[parent[i]]<<":ev\n";
        t2 = below[parent[i]] - below[i] - 1;
        tmp += t2/2.;
        ev[i] = tmp + 1;
    }

    for(int i = 0; i<n; i++){
        cout<<setprecision(7)<<ev[i]<<" ";
    }

    return 0;
}