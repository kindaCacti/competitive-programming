#include <bits/stdc++.h>

using namespace std;

long long n;
vector<vector<long long>> edges, bel;
vector<bool> used;
vector<long long> out;

pair<long long, long long> dfs1(long long cn){
    used[cn] = 1;
    long long below = 1;

    pair<long long, long long> tmp;
    long long sum = 0;
    bel[cn].assign(edges[cn].size(), -1);

    for(int i = 0; i<edges[cn].size(); i++){
        long long node = edges[cn][i];
        if(used[node]) continue;

        tmp = dfs1(node);
        below += tmp.first;
        bel[cn][i] = tmp.first;
        sum += tmp.second;
    }
    return {below, sum + below};
}

void dfs2(long long csum, long long cn){
    out[cn] = csum;
    for(int i = 0; i<edges[cn].size(); i++){
        if(bel[cn][i]==-1) continue;
        dfs2(csum - 2 * bel[cn][i] + n, edges[cn][i]);
    }
}

int main(){
    cin>>n;

    edges.assign(n, {});
    used.assign(n, 0);
    bel.assign(n, {});
    out.assign(n, 0);

    int a, b;
    for(int i = 0; i<n-1; i++){
        cin>>a>>b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    out[0] = dfs1(0).second-n;

    dfs2(out[0], 0);

    for(int i = 0; i<out.size(); i++){
        cout<<out[i]<<" ";
    }

    return 0;
}