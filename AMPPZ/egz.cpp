#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin>>n>>k;

    vector<int> out;
    out.assign(n+1, 0);
    if(n<k*2){
        cout<<"NIE";
        return 0;
    }

    int cp = 1;
    int ck = 1;
    while(cp<n){
        out[cp] = ck;
        ck++;
        cp+=2;
    }

    cp-=1;
    if(cp==n){
        cp-=2;
    }

    ck = n;
    while(cp>=0){
        out[cp] = ck;
        cp -= 2;
        ck--;
    }

    for(int i = 0; i<n; i++){
        cout<<out[i]<<" ";
    }

    return 0;
}