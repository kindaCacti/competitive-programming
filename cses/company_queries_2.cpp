#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dp;
const int LOGN = 20;
int n, q;
vector<int> depth;

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
    cin>>n>>q;

    dp.assign(n, {});
    depth.assign(n, 0);

    dp[0].assign(LOGN, -2);
    int a, sm;
    for(int i = 0; i<n-1; i++){
        dp[i+1].assign(LOGN, -2);
        cin>>a;
        a--;
        depth[i+1] = depth[a] + 1;
        dp[i+1][0] = a;

        for(int j = 1; j<LOGN; j++){
            sm = dp[i+1][j-1];
            if(sm<0) break;
            dp[i+1][j] = dp[sm][j-1];
        }
    }

    int b;
    for(int i = 0; i<q; i++){
        cin>>a>>b;
        a--; b--;
        if(depth[a]>depth[b]){
            a = answ(a, depth[a]-depth[b]);
        }else if(depth[b] > depth[a]){
            b = answ(b, depth[b] - depth[a]);
        }
        cout<<getAnsw(a, b) + 1<<"\n";
    }

    return 0;
}
