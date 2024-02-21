#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;

    long long sum = 0;
    int a;
    for(int i = 0; i<n; i++){
        cin>>a;
        sum+=a;
    }

    long long tmp = sqrt(sum);
    if(tmp*tmp == sum) cout<<"YES";
    else cout<<"NO";
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