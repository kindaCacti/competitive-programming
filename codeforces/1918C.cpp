#include <bits/stdc++.h>

using namespace std;

long long pow(long long a, long long b){
    long long out = 1;
    for(long long i = 0; i<b; i++) out*=a;
    return out;
}

void solve(){
    long long an, bn, r;
    cin>>an>>bn>>r;

    vector<long long> a, b;

    a.assign(63, 0);
    b.assign(63, 0);

    long long diff = abs(an-bn);

    long long ik = 0;
    while(an){
        a[ik++] = an%2;
        an/=2;
    }
    ik = 0;
    while(bn){
        b[ik++] = bn%2;
        bn/=2;
    }

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    long long chdiff = 0;

    if(a.size()==b.size()){
        long long fd = -1;

        for(long long i = 0; i<a.size(); i++){
            if(a[i]>b[i] || b[i] > a[i]){
                fd = i;
                //cout<<i<<" : chd\n";
                break;
            }
        }

        for(long long i = fd + 1; i<a.size(); i++){

            long long tmp = pow(2, a.size()-1-i);
            if(a[i]!=b[i]){
                if(a[i] == 0 and a[fd] == 0 and r >= tmp){
                    chdiff += tmp;
                    r -= tmp;
                }else if(b[i]==0 and b[fd] == 0 and r >= tmp){
                    chdiff += tmp;
                    r -= tmp;
                }
            }
        }

    }


    cout<<diff - chdiff - chdiff<<endl;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}