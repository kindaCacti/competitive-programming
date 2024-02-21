#include <bits/stdc++.h>

using namespace std;

int main(){
    //long long tmp = 1;
    long long cx = 0;
    vector<int> forStack;
    int n;
    cin>>n;

    string a;
    int b;
    bool overflow = false;
    vector<long long> tmp = {1};
    for(int i = 0; i<n; i++){
        cin>>a;
        if(a=="add"){
            if(tmp.size()>1) overflow = true;
            cx += tmp.back();
        }
        if(a=="for"){
            cin>>b;
            tmp.back() *= b;
            if(tmp.back()>4294967295){
                tmp.push_back(1);
            }
            forStack.push_back(b);
        }
        if(a=="end"){
            if(tmp.back()==1 && tmp.size() > 1){
                tmp.pop_back();
            }
            tmp.back() /= forStack.back();
            forStack.pop_back();
        }
        if(cx>4294967295){
            overflow = true;
        }
    }

    if(overflow){
        cout<<"OVERFLOW!!!";
        return 0;
    }
    cout<<cx;
    return 0;
}