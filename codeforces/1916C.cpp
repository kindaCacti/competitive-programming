#include <bits/stdc++.h>

using namespace std;

void solve(){
    int k;
    cin>>k;
    long long a, sum = 0;
    int c = 0;
    int td;
    int odd = 0;
    for(int i = 0; i<k; i++){
        cin>>a;
        sum+=a;
        if(a&1) odd++;
        td = odd/3;
        if(odd%3==1) td++;
        if(odd == 1 && i == 1){
            td = 1;
        }
        if(i==0){
            cout<<sum<<" ";
            continue;
        }
        cout<<sum - td<<" ";
    }
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