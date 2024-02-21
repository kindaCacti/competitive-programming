#include <bits/stdc++.h>
 
using namespace std;
 
const int mod = 1e9+7;
 
int fastPow(int a, int n){
    if(n==0) return 1;
    if(n==1) return a;
 
    long long tmp = fastPow(a, n/2);
    tmp*=tmp;
    tmp%=mod;
    if(n%2) tmp*=a;
    tmp%=mod;
    return tmp;
}
 
int main(){
    int a;
 
    cin>>a;
 
    cout<<fastPow(2, a);
}