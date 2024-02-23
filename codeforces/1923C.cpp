#include <bits/stdc++.h>

using namespace std;

int M = 1e9+7;

void solve(){
    int n, q;
    cin>>n>>q;

    vector<long long> prefix, prones;
    prefix.assign(n+1, 0);
    prones.assign(n+1, 0);

    long long a;
    for(int i = 0; i<n; i++){
        cin>>a;
        prefix[i+1] = prefix[i] + a;
        prones[i+1] = prones[i];
        if(a==1) prones[i+1]++;
    }

    int b;
    long long tmp;
    long long ned = 0;
    while(q--){
        cin>>a>>b;
        a--;
        tmp = prefix[b] - prefix[a];
        ned = b-a;
        ned += prones[b] - prones[a];
        if(ned<=tmp and b-a>1){
            //cout<<prones[a]<<" : "<<prones[b]<< " :prones\n";
            //cout<<ned<<":ned\n";
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}

int main(){
    int t = 1;

    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}