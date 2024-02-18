#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> edges, children;
vector<int> depth;
vector<bool> used;

const int MOD = 998244353;

long long answer = 0;

int delMod(int a, int b){
    long long tmp = a;
    tmp -= b;
    tmp%=MOD;
    tmp+=MOD;
    tmp%=MOD;
    return tmp;
}

int addMod(int a, int b){
    long long tmp = a;
    tmp += b;
    return tmp%MOD;
}

int fastPow(int a, int b){
    if(b==0) return 1;
    if(b==1) return a;
    long long tmp = fastPow(a, b/2);
    tmp *= tmp;
    tmp %= MOD;
    if(b%2) tmp *= a;
    tmp %= MOD;
    return tmp;
}

int dfs(int cn){
    used[cn] = 1;
    int sum = 0, tmp;
    for(int node : edges[cn]){
        if(used[node]) continue;
        depth[node] = depth[cn] - 1;
        tmp = dfs(node);
        sum += tmp; 
        children[cn].push_back(tmp);
        cout<<cn<<" -> "<<node<<" | "<<tmp<<endl;
    }
    return sum + 1;
}

void dfs2(int cn){
    //cout<<"en: "<<cn<<endl;
    for(int node : edges[cn]){
        if(depth[node]<=depth[cn]) continue;
        dfs2(node);
    }

    if(children[cn].size()<=1) return;

    int tmp = 0;
    //cout<<"n: "<<cn<<endl;
    for(int i = 0; i<children[cn].size(); i++){
        tmp += children[cn][i];
        answer = addMod(answer, fastPow(2, children[cn][i]));
    }
    answer = delMod(answer, children[cn].size()-1);
    answer = delMod(answer, fastPow(2, tmp));

}

void solve(){
    answer = 1;

    int n;
    cin>>n;

    for(int i = 0; i<n; i++){
        answer *= 2;
        answer %= MOD;
    }

    used.assign(n, 0);
    depth.assign(n, 0);
    children.assign(n, {});
    edges.assign(n, {});

    int a, b;
    for(int i = 0; i<n-1; i++){
        cin>>a>>b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    int sn = 0;
    for(; sn<n; sn++){
        //cout<<edges[sn].size()<<" : edg\n";
        if(edges[sn].size()>1) break;
    }

    sn %= n;

    dfs(sn);
    dfs2(sn);

    cout<<answer<<"\n";
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}