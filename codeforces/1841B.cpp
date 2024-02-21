#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;

    int asc = 1;
    int ln = -1;
    int fn = -1;
    int a;
    for(int i = 0; i<n; i++){
        cin>>a;
        if(a>=ln){
            if(a>fn and asc==2){
                cout<<0;
                continue;
            }
            cout<<1;
            ln = a;
            if(fn==-1) fn = a;
        }
        else{
            if(asc==2){
                cout<<0;
                continue;
            }
            if(a>fn){
                cout<<0;
                continue;
            }
            cout<<1;
            asc++;
            ln = a;
        }
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}