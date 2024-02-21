#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k;
    cin>>n>>k;
    long long a = 1;
    long long b;
    for(int i = 0; i<n; i++){
        cin>>b;
        a*=b;
    }
    if(2023%a){
        cout<<"NO";
        return;
    }
    cout<<"YES\n";
    cout<<2023/a<<" ";
    for(int i = 0; i<k-1; i++){
        cout<<1<<" ";
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;

    while(t--){
        solve();
        cout<<"\n";
    }
    return 0;
}