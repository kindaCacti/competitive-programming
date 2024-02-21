#include <bits/stdc++.h>

using namespace std;

int nwd(int a, int b){
    if(b==0) return a;
    return nwd(b, a%b);
}

void solve(){
    long long a, b;
    cin>>a>>b;
    int tmp = nwd(a,b);
    int tmp2 = 1;
    if(tmp==a){
        tmp2 = b/a;
    }
    cout<<a*b/tmp * tmp2;
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