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
    int ln = 0;
    int ia = 0;
    int out = 1;
    for(int i = 0; i<n; i++){
        a = nums[i];
        if(ln==a){
            out++;
            ia = 0;
        }
        else if(ln<a){
            if(ia==0){
                ia = 1;
            }if(ia == -1){
                ia = 0;
                out++;
            }
        }
        else if(ln>a){
            if(ia==0){
                ia = -1;
            }if(ia == 1){
                ia = 0;
                out++;
            }
        }
        ln = a;
    }
    int e = 0;
    ln = -1;
    for(int i = 0; i<n; i++){
        e = i;
        if(nums[i]<=ln){
            break;
        }
        ln = nums[i];
    }

    ln = 1e9+7;
    int bt = -1;
    if(e>0){
        bt = nums[e-1];
        out--;
    }
    for(int i = n-1; i>=e; i--){
        if(nums[i]>=ln){
            if(i<n-2) out--;
            break;            
        }else if(nums[i]<=bt){
            break;
        }
        ln = nums[i];
    }
 
    cout<<out<<endl;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        solve();
    }
    return 0;
}