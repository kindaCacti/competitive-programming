#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin>>n;

    string s;
    int count = 0;
    int a;
    for(int i = 0; i<n; i++){
        cin>>s>>a;
        if(count >= 20) break;
        if(s[0] == 'N') continue;
        if(count < 10){
            cout<<i+1<<" ";
            count++;
        }else if(count < 20 and a < 2){
            cout<<i+1<<" ";
            count++;
        }
    }
    return 0;
}