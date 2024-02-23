#include <bits/stdc++.h>

using namespace std;

int M = 1e9+7;

void solve(){
    int n;
    cin>>n;

    int a;
    int sp = -1, ep = -1, os = 0;
    for(int i = 0; i<n; i++){
        cin>>a;
        if(a==1){
            os++;
            if(sp==-1) sp = i;
            ep = i;
        }
    }

    int out = ep - sp + 1 - os;
    cout<<out<<endl;
}

int main(){
    int t = 1;

    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}