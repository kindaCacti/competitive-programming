#include <bits/stdc++.h>

using namespace std;

const int maxn = 5000;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin>>n;
    vector<int> ammounts((n+1)*(n+1)+ 1, 0);
    vector<int> values;
    for(int i = 1; i<=n; i++){
        values.push_back(i*i);
    }


    for(int v1 : values){
        for(int v2 : values){
            if(v1 < v2) continue;
            int tmp = v1 + v2;
            if(tmp >= n*n) continue;
            ammounts[tmp]++;
        }
    }

    int out = 0;
    for(int v1 : values){
        for(int i = 1; i<n; i++){
            int tmp = v1 - i*i;
            if(tmp < 0) continue;

            out += ammounts[tmp];
        }
    }

    cout<<out<<endl;

    return 0;
}