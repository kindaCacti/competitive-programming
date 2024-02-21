#include <bits/stdc++.h>
 
using namespace std;
 
void solve(){
    int a, b;
    cin>>a>>b;
    if(min(a,b)*2<max(a,b)){
        cout<<"NO\n";
        return;
    }
 
    a%=3;
    b%=3;
    if((a+b)%3){
        cout<<"NO\n";
    }else{
        cout<<"YES\n";
    }
}
 
int main(){
    int t;
    cin>>t;
 
    while(t--){
        solve();
    }
    return 0;
}