#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n;
    cin>>n;
 
    long long out = 0;
    int a, la = 0;
    for(int i = 0; i<n; i++){
        cin>>a;
        out+=max(la-a,0);
        la = max(a,la);
    }
    cout<<out;
    return 0;
}