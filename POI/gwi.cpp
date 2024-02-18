#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, s;
    cin>>n>>s;

    long long l, r;
    long long out = 0;
    bool ldone = false, rdone = false;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> bctl, bctr;
    for(int i = 0; i<n-1; i++){
        cin>>l>>r;
        if(i==s-1){
            if(bctr.size()==0){
                out+=r;
                continue;
            }
            if(!rdone) out+=bctr.top();
        }
        if(n-s==i){
            if(bctl.size()==0){
                out+=l;
                continue;
            }
            if(!ldone) out+=bctl.top();
        }
        out += min(l, r);
        if(l<r){
            ldone = true;
        }else{
            rdone = true;
        }
        bctr.push(r-l);
        bctl.push(l-r);
    }

    cout<<out<<endl;
    for(int i = 0; i<n; i++){
        cout<<i+1<<" ";
    }

    return 0;
}