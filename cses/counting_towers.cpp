#include <bits/stdc++.h>
 
using namespace std;
 
const int mod = 1e9+7;
const int maxn = 1e6+1;
 
long long** dp = new long long*[2]{0};
 
void solve(){
    int n = maxn;
    dp[0] = new long long[n+1]{0};
    dp[1] = new long long[n+1]{0};
 
    dp[0][n] = 1;
    dp[1][n] = 1;
 
    for( int i = n-1; i>=0; i--){
        long long tmp1 = dp[0][i+1]; //extending both
        long long tmp2 = (dp[0][i+1]*2)%mod; //extending one of two
        long long tmp3 = (dp[0][i+1] + dp[1][i+1])%mod; //extending none
        long long tmp4 = dp[1][i+1]; //extending double
 
        dp[0][i] = (tmp1+tmp2+tmp3)%mod;
        dp[1][i] = (tmp3+tmp4)%mod;    
    }
}
 
int main(){
    int t;
    cin>>t;
 
    solve();
 
    int x;
    while(t--){
        cin>>x;
 
        cout<<(dp[0][maxn-x+1] + dp[1][maxn-x+1])%mod<<"\n";
    }
    return 0;
}