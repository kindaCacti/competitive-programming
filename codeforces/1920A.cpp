#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;

    int btm = -100, top = 1e9+7;
    vector<int> others;
    int a, b;
    for(int i = 0; i<n; i++){
        cin>>a>>b;
        if(a==1) btm = max(b, btm);
        else if(a==2) top = min(top, b);
        else others.push_back(b);
    }

    int out = top-btm+1;
    for(int tmp : others){
        if(tmp>=btm && tmp<=top){
            out--;
        }
    }

    cout<<max(out, 0);
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