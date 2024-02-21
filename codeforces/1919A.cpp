#include <bits/stdc++.h>

using namespace std;

void solve(){
    int a, b;
    cin>>a>>b;
    long long sum = a;
    a+=b;
    cout<<((a%2)?"Alice":"Bob");
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