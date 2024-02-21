#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> vals;
    vals.assign(n, 0);

    for(int i = 0; i<n; i++){
        cin>>vals[i];
    }

    int out = 0;
    int lf = 1e6, ls = 1e6;
    int tmp;
    for(int i = 0; i<vals.size(); i++){
        tmp = vals[i];
        if(lf < ls && tmp <= lf){
            lf = tmp;
            continue;
        }
        if(ls <= lf && tmp <= ls){
            ls = tmp;
            continue;
        }
        if(tmp <= lf){
            lf = tmp;
            continue;
        }
        if(tmp <= ls){
            ls = tmp;
            continue;
        }
        if(lf <= ls){
            lf = tmp;
            out++;
            continue;
        }
        ls = tmp;
        out++;
        continue;
    }

    cout<<out;
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