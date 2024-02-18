#include <bits/stdc++.h>

using namespace std;

void solve(){
    int k, x, a;
    cin>>k>>x>>a;

    long long tsum = 0;
    long long add = 1;
    for(int i = 0; i<=x; i++){
        tsum+=add;
        if(tsum>a){
            cout<<"NO\n";
            return;
        }
        add = (tsum+1)/(k-1);
        add += (bool)((tsum+1)%(k-1));
    }
    cout<<"YES\n";
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}