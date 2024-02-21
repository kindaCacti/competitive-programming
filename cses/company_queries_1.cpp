#include <bits/stdc++.h>
 
using namespace std;
 
vector<vector<int>> dp;
const int LOGN = 20;
 
int answ(int a, int b){
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
 
int main(){
    int n, q;
    cin>>n>>q;
 
    dp.assign(n, {});
 
    dp[0].assign(LOGN, -2);
    int a, sm;
    for(int i = 0; i<n-1; i++){
        dp[i+1].assign(LOGN, -2);
        cin>>a;
        a--;
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
        a--;
 
        cout<<answ(a, b) + 1<<"\n";
    }
 
    return 0;
}
