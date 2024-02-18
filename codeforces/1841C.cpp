#include <bits/stdc++.h>

using namespace std;

int mpow(int a, int b){
    int out = 1;
    for(int i = 0; i<b; i++) out*=a;
    return out;
}

long long getVal(string s){
    int n = s.size();
    long long sum = 0;
    long long tmp;
    vector<int> dp;
    dp.assign(6, 0);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<s[i]-'A'; j++){
            tmp = ((long long)dp[j] * mpow(10,j));
            sum -= tmp;
            dp[j] = 0;
        }
        dp[s[i]-'A']++;
    }

    for(int i = 0; i<5; i++){
        sum += (long long)dp[i] * mpow(10,i);
    }
    return sum;
}

void solve(){
    string s;
    cin>>s;

    long long out = -1e18;
    string s1;
    vector<int> lettersChanges;
    vector<int> found;
    found.assign(5,0);
    int n = s.size();
    for(int i = 0; i<n; i++){
        if(found[s[i]-'A']==0){
            lettersChanges.push_back(i);
            found[s[i]-'A']++;
        }
    }
    for(int i = n-1; i>=0; i--){
        if(found[s[i]-'A']==1){
            lettersChanges.push_back(i);
            found[s[i]-'A']++;
        }
    }
    for(int j = 0; j<5; j++){
        for(int i = 0; i<lettersChanges.size(); i++){
            s1 = string(s);
            int pos = lettersChanges[i];
            if (pos != std::string::npos)
            {
                s1[pos] = (char)('A'+j);
            }
            //cout<<s1<<endl;
            out = max(out, getVal(s1));
        }
    }

    cout<<out<<endl;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}