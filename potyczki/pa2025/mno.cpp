#pragma GCC optimize("O2")
#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define pii pair<int, int>

unordered_map<long long, long long> rev;
vector<vector<long long>> precalc, precalc2;
map<long long, int> final_digit;
vector<long long> possible_values;
const long long maxn = 1'000'000'000'000'000'000ll;

bool is_overflow(long long a, long long b){
    if(maxn/a <= b) return true;
    return false;
}

void set_possible_values(long long prime){
    long long tmp = 1;
    int lp = possible_values.size()-1;
    while(true){
        if(is_overflow(prime, tmp)) break;
        tmp *= prime;

        for(int i = 0; i<=lp; i++){
            if(is_overflow(tmp, possible_values[i])) continue;
            long long tt = possible_values[i] * tmp;
            if(tt % 10 == 0) continue;
            possible_values.push_back(tt);
        }
    }
}

void setFinalDigits(){
    possible_values.push_back(1);
    set_possible_values(2ll);
    set_possible_values(3ll);
    set_possible_values(5ll);
    set_possible_values(7ll);
    possible_values.push_back(0);


    final_digit[0] = 0;
    final_digit[1] = 1;
    final_digit[2] = 2;
    final_digit[3] = 3;
    final_digit[4] = 4;
    final_digit[5] = 5;
    final_digit[6] = 6;
    final_digit[7] = 7;
    final_digit[8] = 8;
    final_digit[9] = 9;

    sort(possible_values.begin(), possible_values.end());
    for(long long val : possible_values){
        rev[val] = rev.size();
        long long tval = val;
        long long tmp = 1;
        if(val == 0) tmp = 0;
        while(tval){
            tmp *= tval%10;
            tval /= 10;
        }
        final_digit[val] = final_digit[tmp];
    }
}

void set_precalc(){
    setFinalDigits();
    precalc.assign(200, vector<long long>(possible_values.size(), 0));
    precalc2.assign(200, vector<long long>(possible_values.size(), 0));

    for(int i = 1; i<10; i++){
        for(int j = 1; j<=i; j++){
            precalc[i+10][j] = 1;
            precalc2[i+10][j] = 1;
        }
    }

    for(int i = 2; i<20; i++){
        for(long long j = 1; j<10; j++){
            int cpos = i*10+j;
            int lpos = i*10-1;
            for(int k = 0; k<possible_values.size(); k++){
                precalc[cpos][k] += precalc[cpos-1][k];
                precalc2[cpos][k] += precalc2[cpos-1][k];
                if(precalc[lpos][k] == 0) continue;

                long long tmp = possible_values[k] * j;
                if(tmp % 10 == 0) continue;
                precalc[cpos][rev[tmp]] += precalc[lpos][k];
                precalc2[cpos][rev[tmp]] += precalc2[lpos][k];
            }
        }
    }

    for(int i = 2; i<20; i++){
        for(long long j = 1; j<10; j++){
            int cpos = i*10+j;
            int lpos = i*10-1;
            for(int k = 0; k<possible_values.size(); k++){
                precalc[cpos][k] += precalc[lpos][k];
            }
        }
    }
}

void combine_arrays(vector<long long>& arr1, vector<long long>& arr2, long long mul){
    for(int i = 0; i<arr1.size(); i++){
        if(arr2[i]==0)continue;
        long long tmpp = possible_values[i] * mul;
        arr1[rev[tmpp]] += arr2[i];
    }
}

void solve(){
    long long n; cin>>n;

    vector<long long> out(possible_values.size(), 0);

    vector<long long> digits;
    long long tn = n;
    while(tn){
        digits.push_back(tn%10);
        tn /= 10;
    }
    reverse(digits.begin(), digits.end());

    if(digits[0] == 1){
        long long tmpp = (digits.size() - 1)*10 + 9;
        combine_arrays(out, precalc[tmpp], 1ll);
    }

    vector<long long> ans(10, 0);
    long long tmp = 1;
    for(int i = 0; i<digits.size(); i++){
        if(digits[i] == 0){
            tmp = 0;
            break;
        }
        if(digits[i] > 1){
            long long tmpp = (digits.size() - i)*10 + digits[i]-1;
            if(i == 0) combine_arrays(out, precalc[tmpp], tmp);
            else combine_arrays(out, precalc2[tmpp], tmp);
        }
            
        tmp *= digits[i];
    }


    out[rev[tmp]]++;
    for(int i = 0; i<out.size(); i++){
        if(out[i] == 0) continue;
        ans[final_digit[possible_values[i]]] += out[i];
    }

    ans[0] = n;
    for(int i = 1; i<10; i++) ans[0] -= ans[i];

    for(int i = 0; i<10; i++) cout<<ans[i]<<" ";
    cout<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);

    set_precalc();

    int t;
    cin>>t;

    while(t--){
        solve();
    }
}