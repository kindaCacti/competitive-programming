#include <bits/stdc++.h>

using namespace std;

int ST = 120;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n, k;
    cin>>n>>k;

    vector<int> out;
    vector<priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>> starts(ST), ends(ST);
    out.assign(n + 1, 0);
    int a, l, d;
    for(int i = 0; i<k; i++){
        cin>>a>>l>>d;
        if(d>=ST){
            for(int j = 0; j<l; j++){
                out[a+d*j]++;
            }
            continue;
        }
        starts[d].push({(a-1)/d, (a-1)%d});
        ends[d].push({ (a-1)/d + l, (a-1)%d});
    }

    vector<int> mods;
    for(int i = 1; i<ST; i++){
        mods.assign(ST, 0);
        for(int j = 0; j<n; j++){
            if(j%i==0){
                while(starts[i].size() && starts[i].top().first==(j/i)){
                    mods[starts[i].top().second]++;
                    starts[i].pop();
                }
                while(ends[i].size() && ends[i].top().first==(j/i)){
                    mods[ends[i].top().second]--;
                    ends[i].pop();
                }
            }
            out[j+1] += mods[j%i];
        }
    }

    for(int i = 0; i<n; i++){
        cout<<out[i+1]<<" ";
    }

    return 0;
}