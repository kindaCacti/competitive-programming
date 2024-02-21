#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> mods = {(int)1e9+7, (int)1e9+9, 15487429, 15487457};
 
struct HASH{
    vector<long long> vals = {0,0,0,0};
    static const int pow = 31;
 
    int fastPow(int a, int b, int mod){
        if(b==0) return 1;
        if(b==1) return a;
 
        long long tmp = fastPow(a, b/2, mod);
        tmp*=tmp;
        tmp%=mod;
        if(b%2){
            tmp*=a;
            tmp%=mod;
        }
        return tmp;
    }
 
    void addVal(int val, int pos, vector<long long>& mul){
        for(int i = 0; i<vals.size(); i++){
            vals[i] += (((long long)mul[i]*val)%mods[i]);
            vals[i] %= mods[i];
        }
    }
 
    void subVal(int val, int pos, vector<long long>& mul){
        for(int i = 0; i<vals.size(); i++){
            vals[i] -= (((long long)mul[i]*val)%mods[i]);
            vals[i] += mods[i];
            vals[i] %= mods[i];
        }
    }
 
    void multiply(int x = HASH::pow){
        for(int i = 0; i<vals.size(); i++){
            vals[i]*=x;
            vals[i]%=mods[i];
        }
    }
 
    bool compareHash(HASH h){
        for(int i = 0; i<vals.size(); i++){
            if(h.vals[i]!=vals[i]) return false;
        }
        return true;
    }
};
 
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout.tie(0);
 
    string s, m;
    cin>>s>>m;
 
    vector<vector<long long>> powers = {{}};
 
    for(int i = 0; i<mods.size(); i++){
        powers[0].push_back(1);
    }
 
    for(int i = 1; i<s.size(); i++){
        powers.push_back({});
        for(int j = 0; j<mods.size(); j++){
            powers[i].push_back(powers[i-1][j]*HASH::pow);
            powers[i][j] %= mods[j];
        }
    }
 
    if(m.size()>s.size()){
        cout<<0;
        return 0;
    }
 
    HASH pattern, tmp;
    for(int i = 0; i<m.size(); i++){
        tmp.addVal(s[i],i,powers[i]);
        pattern.addVal(m[i],i,powers[i]);
    }
    int out = 0;
    if(tmp.compareHash(pattern))
        out++;
 
    for(int i = m.size(); i<s.size(); i++){
        tmp.subVal(s[i-m.size()],i-m.size(),powers[i-m.size()]);
        tmp.addVal(s[i],i,powers[i]);
        pattern.multiply();
        if(tmp.compareHash(pattern))
            out++;
    }
 
    cout<<out;
 
    return 0;
}