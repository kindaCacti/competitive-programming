#include <iostream>
 
using namespace std;
 
const int mod = 1e9+7;
 
int main(){
    int n, t;
    cin>>n>>t;
    long long* mins = new long long[t+1]{0};
    int* nums = new int[n];
    for(int i = 0; i<n; i++){
        cin>>nums[i];
    }
    mins[0] = 1;
 
    for(int i = 0; i<t; i++){
        for(int j = 0; j<n; j++){
            if(i+nums[j]>t) continue;
            mins[i+nums[j]] += mins[i];
            mins[i+nums[j]]%=mod;
        }
    }
 
    cout<<mins[t];
 
    return 0;
}