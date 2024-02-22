#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    n += n;

    int a;
    vector<int> nums;
    for(int i = 0; i<n; i++){
        cin>>a;
        nums.push_back(a);
    }

    sort(nums.begin(), nums.end());

    long long out = 0;
    while(nums.size()){
        if(nums.size()%2==1) out += nums.back();
        nums.pop_back();
    }

    cout<<out<<endl;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}