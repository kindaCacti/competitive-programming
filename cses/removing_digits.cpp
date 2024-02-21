#include <bits/stdc++.h>
 
using namespace std;
 
const int mod = 1e9+7;
 
vector<int> genDigits(int n){
    vector<int> out;
    while(n){
        if(n%10)
            out.push_back(n%10);
        n/=10;
    }
    return out;
}
 
int main(){
    int n;
    cin>>n;
    int* dp = new int[n+1];
    for(int i = 0; i<n; i++){
        dp[i] = 1e9;
    }
    dp[n] = 0;
 
    vector<int> tmp;
    for(int i = n; i>=0; i--){
        if(dp[i]==1e9) continue;
        tmp = vector<int>(genDigits(i));
        for(int j = 0; j<tmp.size(); j++){
            dp[i-tmp[j]] = min(dp[i-tmp[j]], dp[i]+1);
        }
    }
 
    cout<<dp[0];
 
    return 0;
}