#include <iostream>
 
using namespace std;
 
int main(){
    int n, t;
    cin>>n>>t;
    int* mins = new int[t+1]{0};
    for(int i = 0; i<=t; i++){
        mins[i] = 1e9;
    }
    int* nums = new int[n];
    for(int i = 0; i<n; i++){
        cin>>nums[i];
    }
    mins[0] = 0;
 
    for(int i = 0; i<t; i++){
        for(int j = 0; j<n; j++){
            if(i+nums[j]>t) continue;
            mins[i+nums[j]] = min(mins[i+nums[j]], mins[i]+1);
        }
    }
    if(mins[t]==1e9){
        cout<<-1;
        return 0;
    }
    cout<<mins[t];
 
    return 0;
}