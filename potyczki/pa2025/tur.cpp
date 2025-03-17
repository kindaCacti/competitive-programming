#include <bits/stdc++.h>

using namespace std;

#define int long long

vector<int> input;
int n;

int binom_3(int n){
    return ((n) * (n-1) * (n-2)) / 6ll;
}

int binom_2(int n){
    return ((n) * (n-1)) / 2ll;
}

bool check_possible(int amm){
    int l = 0, r = amm, cnt = 0;
    for(int i = 0; i<n; i++){
        if(input[i] == 0) continue;
        while(true){
            cnt++;
            r--;
            if(r < 0) return false;

            if(l*r >= input[i]) break;

            int tmp = l * r * cnt + binom_2(cnt) * (amm-cnt) + binom_3(cnt);
            if(tmp >= input[i]) break;;
        }
        l = amm-r;
        cnt = 0;
    }

    return true;
}

void solve(){
    cin>>n;
    input.assign(n, 0);

    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    int mn = 0, mx = 1000000000ll, mid;

    while(mn < mx){
        mid = (mn + mx) / 2ll;

        if(check_possible(mid)) mx = mid;
        else mn = mid + 1;
    }

    cout<<mn<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin>>t;

    while(t--) solve();
    return 0;
}