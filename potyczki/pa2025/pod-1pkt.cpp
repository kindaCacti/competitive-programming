#pragma GCC optimize("O2")
#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define int long long

vector<vector<int>> count_for;
vector<vector<int>> chkc;
vector<string> substrings;
string s;
const int max_letters = 6;
const int mod = 998'244'353;

bool check_multiplicity(string& pat){
    vector<int> dp(s.size(), 0);
    int cpos = 0;
    bool has_wiggle = false;
    for(int i = 0; i<s.size(); i++){
        if(cpos == pat.size() and pat[cpos-1] == s[i]) has_wiggle = true;
        if(cpos < pat.size()){
            if(s[i] == pat[cpos]) cpos++;
            else if(cpos > 0 and pat[cpos-1] == s[i]) has_wiggle = true;
        }
    }

    if(cpos >= pat.size() and has_wiggle) return true;
    return false;
}

int count_substrings(){
    chkc.assign(max_letters, vector<int>(1, 0));
    count_for.assign(1, vector<int>(max_letters, 0));
    substrings.assign(1, "");

    for(char a : s){
        vector<int> tmp;
        int let = a - 'a';
        for(int pos : chkc[let]){
            if(count_for[pos][let] > 0) continue;
            count_for[pos][let]++;

            string new_substring(substrings[pos]);
            new_substring.push_back(a);
            tmp.push_back(substrings.size());
            substrings.push_back(new_substring);
            count_for[pos][let]++;
            count_for.push_back(vector<int>(max_letters, 0));            
        }

        chkc[let].clear();
        for(int val : tmp){
            for(int i = 0; i<max_letters; i++){
                chkc[i].push_back(val);
            }
        }
    }

    int out = 0;
    for(string& su : substrings){
        if(su.size() == 0) continue;
        out += (int)check_multiplicity(su);
        out %= mod;
    }

    return out;
}

signed main(){
    int n, q;
    cin>>n>>q;
    cin>>s;

    cout<<count_substrings()<<endl;

    for(int i = 0; i<q; i++){
        int a;
        char c;
        cin>>a>>c;
        a--;
        s[a] = c;
        cout<<count_substrings()<<endl;
    }
    return 0;
}