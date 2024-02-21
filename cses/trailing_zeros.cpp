#include <bits/stdc++.h>
//#include <algorithm>
 
using namespace std;
 
int main(){
    int n;
    cin>>n;
 
    int k = 5;
    long long out = 0;
    while(k<=n){
        out+=(n/k);
        k*=5;
    }
 
    cout<<out;
    return 0;
}