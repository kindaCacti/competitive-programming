#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    string a;
    cin>>a;
 
    sort(a.begin(), a.end());
    vector<string> out;
    do{
        out.push_back(a);
    }while(next_permutation(a.begin(), a.end()));
    cout<<out.size()<<endl;
    for(int i = 0; i<out.size(); i++){
        cout<<out[i]<<endl;
    }
    return 0;
}