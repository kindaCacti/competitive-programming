#include <bits/stdc++.h>
 
using namespace std;
 
void solve(){
    long long ax, ay, bx, by, cx, cy;
    cin>>ax>>ay>>bx>>by>>cx>>cy;
    long long tmp = (bx - ax)*(cy - ay) - (by - ay)*(cx - ax);
    if(tmp>0) cout<<"LEFT";
    else if(tmp==0) cout<<"TOUCH";
    else cout<<"RIGHT";
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
