#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n;
    cin>>n;
    if(n==1){
        cout<<1;
        return 0;
    }
    if(n<4){
        cout<<"NO SOLUTION";
        return 0;
    }
 
    if(n==4){
        cout<<"2 4 1 3";
        return 0;
    }
 
    int mid = (n+1)/2;
 
    for(int i = 1; i<=mid; i++){
        cout<<i<<" ";
        if(mid+i<=n){
            cout<<mid+i<<" ";
        }
    }
 
    return 0;
}