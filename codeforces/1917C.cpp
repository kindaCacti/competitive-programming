#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k, d;
    cin>>n>>k>>d;

    vector<int> nums, additions;
    int a;
    for(int i = 0; i<n; i++){
        cin>>a;
        nums.push_back(a);
    }
    for(int i = 0; i<k; i++){
        cin>>a;
        additions.push_back(a);
    }

    int tmp = min(n*2, d-1);
    int out = 0;
    int tsum = 0;
    for(int j = 0; j<n; j++){
        if(nums[j]==j+1){
            tsum++;
        }
    }
    tsum += ((d-1)/2);
    out = max(out, tsum);
    //cout<<out<<":tout\n";
    for(int i = 0; i<tmp; i++){
        tsum = 0;
        for(int j = 0; j<additions[i%k]; j++){
            nums[j]++;
        }
        for(int j = 0; j<n; j++){
            if(nums[j]==j+1){
                tsum++;
            }
        }
        tsum += ((d-i-2)/2);
        out = max(out, tsum);
        //cout<<out<<":tout\n";
    }
    cout<<out;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;

    while(t--){
        solve();
        cout<<"\n";
    }

    return 0;
}