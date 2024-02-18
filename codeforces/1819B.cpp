#include <bits/stdc++.h>

using namespace std;

bool isPossible(vector<pair<long long, long long>>& pairs, vector<pair<long long, long long>>& rpairs, pair<long long, long long> div){
    long long p1 = 0, p2 = 0;
    pair<long long, long long> tmps = {div.first, div.second};
    map<pair<long long, long long>, long long> used1, used2;
    while(p1<pairs.size() && p2<pairs.size()){
        //cout<<p1<<" : "<<p2<<endl;
        while(used2[pairs[p1]]>0){
            used2[pairs[p1]]--;
            p1++;
        }
        while(used1[rpairs[p2]]>0){
            used1[rpairs[p2]]--;
            p2++;
        }
        if(p1==pairs.size() && p2 == pairs.size()) break;
        if(pairs[p1].first == tmps.first){
            tmps.second -= pairs[p1].second;
            used1[{pairs[p1].second, pairs[p1].first}]++;
            p1++;
            continue;
        }
        if(rpairs[p2].first == tmps.second){
            tmps.first -= rpairs[p2].second;
            used2[{rpairs[p2].second, rpairs[p2].first}]++;
            p2++;
            continue;
        }
        return false;
    }
    return true;
}

void solve(){
    vector<pair<long long, long long>> answ;
    long long n;
    cin>>n;

    long long a, b;
    vector<pair<long long, long long>> pairs, rpairs;
    long long ma = 0, mb = 0;
    long long tn = 0;
    for(long long i = 0; i<n; i++){
        cin>>a>>b;
        pairs.push_back({a,b});
        rpairs.push_back({b,a});
        ma = max(ma, a);
        mb = max(mb, b);
        tn += (long long)a*b;
    }

    sort(pairs.begin(), pairs.end());
    reverse(pairs.begin(), pairs.end());
    sort(rpairs.begin(), rpairs.end());
    reverse(rpairs.begin(), rpairs.end());

    vector<pair<long long, long long>> divs;

    //cout<<tn<<"\n";

    bool done = false;
    if(tn%ma == 0){
        divs.push_back({ma, tn/ma});
        done = true;
    }
    if(!done || (n>1 & tn%mb==0))
        divs.push_back({tn/mb, mb});

    //cout<<divs.size()<<"size\n";
    for(pair<long long, long long> div : divs){
        if(isPossible(pairs, rpairs, div)) answ.push_back({div.first, div.second});
    }

    cout<<answ.size()<<"\n";
    for(pair<long long, long long> tmp : answ){
        cout<<tmp.first<<" "<<tmp.second<<"\n";
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    long long t;
    cin>>t;

    while(t--){
        solve();
    }
    return 0;
}