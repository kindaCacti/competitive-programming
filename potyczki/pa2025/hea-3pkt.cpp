#pragma GCC optimize("O2")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pii pair<int, int>

vector<int> routers;
vector<vector<pii>> edges;
vector<vector<int>> values_at;
vector<unordered_set<int>> inserted;
int n;
const int inf = 1000000007;

void do_step(){
    vector<vector<int>> tmp_vals(n);
    for(int i = 0; i<n; i++){
        for(pii edge : edges[i]){
            for(int j = 0; j<values_at[i].size(); j++){
                int tmp = values_at[i][j] * edge.second;
                if(tmp > routers[edge.first]) continue;
                if(inserted[edge.first].find(tmp) != inserted[edge.first].end()) continue;
                inserted[edge.first].insert(tmp);
                tmp_vals[edge.first].push_back(tmp);
            }
        }
    }

    values_at = vector<vector<int>>(tmp_vals);
}

int simulate(){
    values_at.assign(n, {});
    values_at[0].push_back(1);
    inserted.assign(n, {});
    int out = -1;
    // the edges with value one are a problem (to fix)
    for(int i = 0; i<n* 60; i++){
        do_step();
        for(int val : values_at[n-1]){
            out = max(out, val);
        }
    }

    return out;
}

vector<bool> done;

void dfs(int sn, int cn){
    done[cn] = 1;

    for(pii nn : edges[cn]){
        if(nn.second != 1) continue;
        if(done[nn.first]) continue;
        edges[sn].push_back({nn.first, 1});
        dfs(sn, nn.first);
    }
}

void combine_ones(){
    for(int i = 0; i<n; i++){
        done.assign(n, 0);
        dfs(i, i);
    }
}

bool do_shortening(int cn){
    bool shortened = false;
    for(int i = 0; i<edges[cn].size(); i++){
        pii nn = edges[cn][i];
        if(nn.first == n-1) continue;
        if(edges[nn.first].size() != 1) continue;
        shortened = true;
        int tmp = edges[nn.first][0].second * edges[cn][i].second;
        tmp = min(tmp, inf);
        edges[cn][i] = {edges[nn.first][0].first, tmp};
    }

    return shortened;
}

void shorten_paths(){
    bool shortened = false;
    for(int it = 0; it<60; it++){
        shortened = false;
        for(int i = 0; i<n; i++){
            shortened |= do_shortening(i);
        }
    };
}

void solve(){
    int k;
    cin>>n>>k;

    routers.assign(n, 0);
    edges.assign(n, {});
    for(int i = 0; i<n; i++){
        cin>>routers[i];
    }

    for(int i = 0; i<k; i++){
        int a, b, p;
        cin>>a>>b>>p;
        a--; b--;

        edges[a].push_back({b, p});
    }

    //shorten_paths();
    //combine_ones();

    cout << simulate() << endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);

    int t; cin>>t;

    while(t--) solve();
    return 0;
}