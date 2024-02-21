#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    set<char> con = {'b', 'c', 'd'};
    set<char> vow = {'a', 'e'};

    vector<string> syl;
    string tmp = "";
    string pos = "";
    int td = 0;
    for(int i = n-1; i>=0; ){
        if(i-1>=0){
            tmp.clear();
            for(int j = i-1; j<=i; j++){
                tmp.push_back(s[j]);
            }
            if(con.find(tmp[0])!=con.end() && vow.find(tmp[1])!=vow.end()){
                pos = string(tmp);
                td = 2;
            }
        }
        if(i-2>=0){
            tmp.clear();
            for(int j = i-2; j<=i; j++){
                tmp.push_back(s[j]);
            }
            if(con.find(tmp[0])!=con.end() && vow.find(tmp[1])!=vow.end() && con.find(tmp[2])!=con.end()){
                pos = string(tmp);
                td = 3;
            }
        }
        syl.push_back(string(pos));
        i-=td;
    }

    for(int i = syl.size()-1; i>=0; i--){
        cout<<syl[i];
        if(i>0) cout<<".";
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