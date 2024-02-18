#include <bits/stdc++.h>

using namespace std;

int LOG = 20;
vector<vector<int>> edges, dp;
vector<bool> used;
vector<int> depth;

void dfs(int cn, int dpt = 0, int ln = -1){
    used[cn] = 1;
    depth[cn] = dpt;
    dp[cn][0] = ln;

    int k = 1, nn;
    while(dp[cn][k-1] > -1){
        nn = dp[cn][k-1];
        dp[cn][k] = dp[nn][k-1];
        k++;
    }

    for(int node : edges[cn]){
        if(used[node]) continue;
        dfs(node, dpt+1, cn);
    }
}

int answ(int a, int b){
    if(b==0) return a;
    vector<int> bits;
    while(b){
        bits.push_back(b%2);
        b/=2;
    }

    reverse(bits.begin(), bits.end());
    int cn = a;

    for(int i = 0; i<bits.size(); i++){
        if(bits[i]==0) continue;
        cn = dp[cn][bits.size()-i-1];
        if(cn<0) break;
    }
    return cn;
}

int getAnsw(int ak, int bk){
    if(ak==bk) return ak;


    if(depth[bk] > depth[ak])
        swap(ak, bk);

    ak = answ(ak, depth[ak]-depth[bk]);
    int k;
    while(ak!=bk){
        k = 0;
        while(dp[ak][k]!=dp[bk][k]){
            k++;
        }
        if(k==0){
            ak = dp[ak][k];
            bk = dp[bk][k];
            break;
        }
        ak = dp[ak][k-1];
        bk = dp[bk][k-1];
    }

    return ak;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n, q;
    cin>>n>>q;
    edges.assign(n, {});

    int a, b;
    for(int i = 0; i<n-1; i++){
        cin>>a>>b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    dp.assign(n, {});
    for(int i = 0; i<n; i++){
        dp[i].assign(LOG, -1);
    }
    used.assign(n, 0);
    depth.assign(n, 0);
    dfs(0);

    for(int i = 0; i<q; i++){
        cin>>a>>b;
        a--; b--;
        int tmp = getAnsw(a, b);
        int out = depth[a] + depth[b] - 2 * depth[tmp];
        cout<<out<<"\n";
    }

    return 0;
}