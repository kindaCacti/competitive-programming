#include <bits/stdc++.h>
 
using namespace std;
 
void solve(){
    int x, y;
    cin>>y>>x;
    long long dist = max(x, y);
 
    long long sn = (dist-1)*(dist-1);
    if(dist%2){
        sn+=x;
        if(x==dist){
            sn+=dist;
            sn-=y;
        }
    }else{
        sn+=y;
        if(y==dist){
            sn+=dist;
            sn-=x;
        }
    }
 
    cout<<sn<<"\n";
}
 
int main(){
    int t;
    cin>>t;
 
    while(t--){
        solve();
    }
 
    return 0;
}