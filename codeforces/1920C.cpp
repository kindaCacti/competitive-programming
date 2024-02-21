#include <bits/stdc++.h>

using namespace std;

vector<int> divs;

int gcd(int a, int b){
    if(a==0) return b;
    return gcd(b%a, a);
}

void solve(){
    divs.clear();
    int n;
    cin>>n;
    vector<int> nums;
    nums.assign(n, 0);

    for(int i = 0; i<n; i++) cin>>nums[i];

    for(int i = 1; i*i<=n; i++){
        if(n%i) continue;
        divs.push_back(i);
        if((n/i)^i) divs.push_back(n/i);
    }

    int out = 0;
    int tmp = nums[0];
    int tt;
    for(int i = 0; i<divs.size(); i++){
        if(divs[i]==n){
            out++;
            continue;
        }
        tmp = 0;
        //cout<<divs[i]<<" . "<<tmp<<endl;
        for(int k = 0; k<divs[i]; k++){
            for(int j = k; j<n; j+=divs[i]){
                if(j+divs[i]>=n) continue;
                tt = gcd(tmp, abs(nums[j] - nums[j+divs[i]]));
                if(tt^0) tmp = tt;
                if(tmp == 0) tmp = tt;
            }
        }
        if(tmp^1) out++;
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