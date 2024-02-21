#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> nums, presum;

long long getAnsw(int k, int x){
    int spos = k;
    int epos = max(0, k-x);

    //cout<<spos<<" - "<<epos;

    long long out = - presum[spos] + 2ll * presum[epos];
    //cout<<" "<<presum[spos]<<" "<<presum[epos];
    //cout<<" o "<<out<<endl;
    return out;
}    

void solve(){
    int x, k;
    cin>>n>>k>>x;
    nums.assign(n, 0);
    presum.assign(n+1, 0);
    for(int i = 0; i<n; i++){
        cin>>nums[i];
    }

    sort(nums.begin(), nums.end());
    //reverse(nums.begin(), nums.end());
    int it = 1;
    for(int i : nums){
        presum[it] = presum[it-1] + i;
        it++;
    }

    long long out = -1e18;;

    for(int i = 0; i<=k; i++){
        out = max(out, getAnsw(n-i, x));
    }

    cout<<out;

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