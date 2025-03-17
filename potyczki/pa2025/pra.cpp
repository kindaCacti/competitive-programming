#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
int n, k, t;
vector<pii> presum;

int calc(int l, int r){
    l--;
    //r++;
    int ll = l-t;
    int rr = r+t;

    int ws = presum[l].second - presum[ll].second;
    ws += presum[rr].second - presum[r].second;
    int missed = presum[l].first - presum[ll].first;
    missed += presum[rr].first - presum[r].first;
    missed += ws;
    missed += presum[ll].first + presum.back().first - presum[rr].first;

    if(missed > k) return -1;

    ws = presum[rr].second - presum[ll].second;
    int tmp = k - missed;
    int left_meetings = max(presum.back().second - ws - tmp, 0);
    return n - rr + ll - left_meetings;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>k>>t;
    presum.push_back({0,0});
    for(int i = 0; i<n; i++){
        char a;
        cin>>a;
        presum.push_back(pii(presum.back()));
        if(a == '1') presum.back().first++;
        if(a == '2') presum.back().second++;
    }

    int out = -1;
    if(presum.back().first <= k){
        int tmp = k - presum.back().first;
        int rem = max(0, presum.back().second - tmp);
        out = n-rem;
    }

    for(int i = t+1; i<n; i++){
        for(int j = i; j<=n-t; j++){
            out = max(out, calc(i, j));
        }
    }

    cout<<out<<endl;
}