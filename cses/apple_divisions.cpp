#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    vector<long long> vals = {0};
 
    int n;
    cin>>n;
    long long sum = 0;
    int a;
    for(int i = 0; i<n; i++){
        cin>>a;
        sum+=a;
        for(int j = vals.size()-1; j>=0; j--){
            vals.push_back(vals[j]+a);
        }
    }
    long long mid = sum/2;
    long long closest = sum+1;;
    for(int i = 0; i<vals.size(); i++){
        if(abs(vals[i]-mid)<abs(mid-closest)){
            closest = vals[i];
        }
    }
 
    cout<<abs((sum-closest)-closest);
 
    return 0;
}