#include <bits/stdc++.h>

using namespace std;

void solve(){
    int a, b, c;
    cin>>a>>b>>c;
    if(a==b){
        cout<<c;
        return;
    }
    if(a==c){
        cout<<b;
        return;
    }
    cout<<a;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        solve();
        cout<<"\n";
    }

    return 0;
}