#include <bits/stdc++.h>

using namespace std;

int M = 1e9+7;

int abss(int a){
    if(a<0) return -a;
    return a;
}

void solve(){
    int n, k;
    cin>>n>>k;

    vector<pair<int, int>> monsters;
    monsters.assign(n, {0,0});
    int a;
    for(int i = 0; i<n; i++){
        cin>>a;
        monsters[i].second = a;
    }

    for(int i = 0; i<n; i++){
        cin>>a;
        monsters[i].first = abss(a);
    }

    sort(monsters.begin(), monsters.end());

    int pastRoudns = 0;
    int rd = 0;
    int tmp = k;
    while(rd < monsters.size()){
        if(monsters[rd].first <= pastRoudns){
            //cout<<pastRoudns<<" "<<monsters[rd].first<<" "<<monsters[rd].second<<": rd\n";
            cout<<"NO\n";
            return;
        }
        tmp = k;
        while(rd<monsters.size() and tmp){
            if(monsters[rd].second <= tmp){
                tmp -= monsters[rd].second;
                rd++;
            }else{
                monsters[rd].second -= tmp;
                tmp = 0;
            }
        }
        pastRoudns++;
    }
    cout<<"YES\n";
}

int main(){
    int t = 1;

    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}