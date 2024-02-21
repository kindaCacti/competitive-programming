#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;

    vector<int> nums;
    int a;
    for(int i = 0; i<n; i++){
        cin>>a;
        nums.push_back(a);
    }

    set<long long> ext = {0};
    pair<long long, long long> tmp = {0,0};
    long long sub;
    for(int i = 0; i<nums.size(); i++){
        if(i%2) tmp.first += nums[i];
        else tmp.second += nums[i];

        sub = tmp.first - tmp.second;
        if(ext.find(sub) != ext.end()){
            cout<<"YES";
            return;
        }
        ext.insert(sub);
    }
    cout<<"NO";
}

int main(){
    int t;
    cin>>t;

    while(t--){
        solve();
        cout<<"\n";
    }
    return 0;
}