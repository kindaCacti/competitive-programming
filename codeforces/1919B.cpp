#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;

    int p = 0, m = 0;
    char a;
    for(int i = 0; i<n; i++){
        cin>>a;
        if(a=='-') m++;
        else p++;
    }

    cout<<abs(p-m);
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