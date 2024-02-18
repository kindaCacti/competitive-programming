#include <bits/stdc++.h>

using namespace std;

vector<int> divs;
set<int> divsUsed;

void getDivs(int a){
    for(int i = 1; i*i<=a; i++){
        if(a%i) continue;
        if(divsUsed.find(i) == divsUsed.end()){
            divs.push_back(i);
            divsUsed.insert(i);
        }
        int tmp = a/i;
        if(divsUsed.find(tmp) == divsUsed.end()){
            divs.push_back(tmp);
            divsUsed.insert(tmp);
        }
    }
}

void solve(){
    int x, t;
    cin>>x>>t;

    divs.clear();
    divsUsed.clear();

    int a = x - t;
    int b = x + t - 2;

    getDivs(a);
    getDivs(b);

    int out = 0;
    int tmp;
    for(int div : divs){
        //cout<<div<<":d\n";
        if(div%2) continue;
        tmp = (div+2)/2;
        if(tmp>=t) out++;
    }    

    cout<<out<<endl;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}