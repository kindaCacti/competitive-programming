#include <bits/stdc++.h>
 
using namespace std;
 
const int mod = 1e9+7;
 
int main(){
    int n, m;
    cin>>n>>m;
 
    long long** dp = new long long*[n];
    int* nums = new int[n]{0};
    for(int i = 0; i<n; i++){
        dp[i] = new long long[m+1]{0};
        cin>>nums[i];
    }
 
    for(int i = 0; i<=m; i++){
        dp[0][i] = 1;
    }
 
    int tmp;
    for(int i = 1; i<n; i++){
        tmp = nums[i-1];
        if(tmp>0){
            for(int k = -1; k<2; k++){
                if(tmp+k<1||tmp+k>m) continue;
                dp[i][tmp+k] = dp[i-1][tmp];
            }
            continue;
        }
 
        for(int j = 1; j<=m; j++){
            for(int k = -1; k<2; k++){
                if(j+k<1||j+k>m) continue;
                dp[i][j+k] += dp[i-1][j];
                dp[i][j+k] %= mod;
            }
        }
    }
 
    long long out = 0;
    if(nums[n-1]!=0){
        cout<<dp[n-1][nums[n-1]];
    }else{
        for(int i = 1; i<=m; i++){
            out+=dp[n-1][i];
            out%=mod;
        }
        cout<<out;
    }
 
    return 0;
}
