#include <bits/stdc++.h>
 
using namespace std;
 
const int mod = 1e9+7;
 
int main(){
    int n;
    cin>>n;
    long long** dp = new long long*[n];
    char a;
    for(int i = 0; i<n; i++){
        dp[i] = new long long[n]{0};
        for(int j = 0; j<n; j++){
            cin>>a;
            if(a=='*'){
                dp[i][j] = -1;
            }
        }
    }
 
    if(dp[0][0]==-1){
        cout<<0;
        return 0;
    }
    dp[0][0] = 1;
 
    long long tmp;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(dp[i][j]<=0) continue; 
            if(i+1<n){
                if(dp[i+1][j]!=-1){
                    dp[i+1][j] += dp[i][j];
                    dp[i+1][j]%=mod;
                }
            }if(j+1<n){
                if(dp[i][j+1]!=-1){
                    dp[i][j+1] += dp[i][j];
                    dp[i][j+1] %= mod;
                }
            }
        }
    }
 
    cout<<max(0ll,dp[n-1][n-1]);
    return 0;
}
