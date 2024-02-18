#include <bits/stdc++.h>

using namespace std;

int main(){
    int n = 50;

    vector<long long> out;
    out.assign(n+1, 0);
    out[0] = 1;

    for(int i = 0; i<=n; i++){
        for(int j = 1; j<=4; j++){
            if(j+i>n) break;

            out[i+j] += out[i];
        }
    }

    cout<<out[n];

    return 0;
}