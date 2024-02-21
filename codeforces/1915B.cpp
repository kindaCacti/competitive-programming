#include <bits/stdc++.h>

using namespace std;

void solve(){
    char out = 'D';
    char tmp;
    set<char> used;
    for(int i = 0; i<3; i++){
        used.clear();
        for(int j = 0; j<3; j++){
            cin>>tmp;
            if(tmp!='?') used.insert(tmp);
        }
        if(used.size()<3){
            if(used.find('A')==used.end()){
                cout<<'A';
            }else if(used.find('B')==used.end()){
                cout<<'B';
            }else{
                cout<<'C';
            }
        }
    }
}

int main(){
    int t;
    cin>>t;

    while(t--){
        solve();
        cout<<"\n";
    }

    return 0;
}