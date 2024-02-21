#include <bits/stdc++.h>
 
using namespace std;
 
const int maxsize = 100002;
 
int main(){
    bitset<maxsize> plecak;
    int n;
    cin>>n;
 
    plecak.set(0);
    int a;
    for(int i = 0; i<n; i++){
        cin>>a;
        plecak |= (plecak<<(a));
    }
 
    vector<int> out;
 
    for(int i = 1; i<maxsize; i++){
        if(plecak.test(i)){
            out.push_back(i);
        }
    }
    cout<<out.size()<<"\n";
    for(int i = 0; i<out.size(); i++){
        cout<<out[i]<<" ";
    }
    return 0;
}