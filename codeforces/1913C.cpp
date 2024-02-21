#include <bits/stdc++.h>

using namespace std;
map<int, int> vals;

bool exists(int a){
    vector<int> bits;
    while(a){
        bits.push_back(a%2);
        a/=2;
    }

    int cneeded = 0;
    for(int i = bits.size()-1; i>=0; i--){
        cneeded*=2;
        cneeded+=bits[i];

        cneeded = max(0, cneeded-vals[i]);
    }
    if(cneeded == 0) return true;
    return false;
}

int main(){
    int n;
    cin>>n;

    int a, b;
    while(n--){
        cin>>a>>b;
        if(a==1) vals[b]++;
        else cout<<(exists(b)?"YES\n":"NO\n");
    }

    return 0;
}