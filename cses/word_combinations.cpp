#include <bits/stdc++.h>
 
using namespace std;
 
const int mod = 1e9+7;
 
struct NODE{
    int val = 0;
    map<char, int> neighbours;
};
 
struct TRIE{
    vector<NODE> nodes = {NODE()};
 
    void addString(string s){
        int k = 0;
 
        for(int i = 0; i<s.size(); i++){
            if(nodes[k].neighbours.find(s[i])!=nodes[k].neighbours.end()){
                k = nodes[k].neighbours[s[i]];
            }else{
                nodes[k].neighbours[s[i]] = nodes.size();
                nodes.push_back(NODE());
                k = nodes.size()-1;
            }
        }
 
        nodes[k].val = 1;
    }
    void updateDP(long long* &dp, string str, int s){
        int k = 0;
        for(int i = s; i<str.size(); i++){
            //cout<<str[i]<<" : "<<s<<"ll";
            if(nodes[k].neighbours.find(str[i])==nodes[k].neighbours.end()) break;
            k = nodes[k].neighbours[str[i]];
            //cout<<nodes[k].val<<endl;
            if(nodes[k].val){
                //cout<<"\n  c"<<i+1<<"c  \n";
                dp[i+1] += dp[s];
                dp[i+1] %= mod;
            }
        }
    }
};
 
int main(){
    string s;
    cin>>s;
    int n;
    cin>>n;
    TRIE t;
    string a;
    long long* dp = new long long[s.size()+1]{0};
    dp[0] = 1;
    for(int i = 0; i<n; i++){
        cin>>a;
        t.addString(a);
    }
 
    for(int i = 0; i<s.size(); i++){
        t.updateDP(dp, s, i);
        //cout<<dp[i]<<":dpdp   \n";
    }
 
    cout<<dp[s.size()];
 
    return 0;
}
