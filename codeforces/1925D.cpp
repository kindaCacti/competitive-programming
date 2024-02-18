#include <bits/stdc++.h>

using namespace std;

vector<long long> binomials; //0 - (n 0), 1 - (n 1) ...

long long M = 1e9+7;

long long fastPow(long long a, long long b){
    if(b==0) return 1;
    if(b==1) return a;

    long long tmp = fastPow(a, b/2);
    tmp *= tmp;
    tmp %= M;
    if(b%2) tmp*=a;
    tmp %= M;
    return tmp;
}

long long delMod(long long a, long long b){
    long long tmp = a;
    tmp -= b;
    tmp += M;
    return tmp%M;
}

pair<long long, long long> ext_euc(long long a, long long b){
    if(a==0) return {0, 1};
    pair<long long, long long> tmp = ext_euc(b%a, a);
    long long tp = tmp.second - (b/a) * tmp.first;
    tp%=M;
    while(tp<0){
        tp += M;
    }

    return {tp%M, tmp.first%M};
}

void genBins(long long k){
    long long tmp = 1;
    for(int i = 2; i<=k; i++){
        tmp *= i;
        tmp %= M;
    }

    long long tmp2 = tmp;
    long long tmp3 = 1;
    long long tmp4 = 1;
    long long ndiv, ndiv2;
    for(int i = 0; i<=k; i++){
        ndiv = ext_euc((tmp2*tmp3)%M, M).first;
        //cout<<ndiv<<" "<<tmp2*tmp3<<" :t "<<tmp<<" : "<<(ndiv*tmp)%M<<" : bin\n";
        tmp4 *= (k-i);
        tmp4%=M;
        binomials.push_back((ndiv*tmp)%M);
        ndiv2 = ext_euc((tmp4)%M, M).first;
        tmp2 = tmp * ndiv2;
        tmp2%=M;
        tmp3*=(i+1);
        tmp3%=M;
    }
}

void solve(){
    long long n, m, k;
    cin>>n>>m>>k;

    binomials.clear();
    genBins(k);

    int ik = 0;
    //for(int bin : binomials){
    //    cout<<bin<<" : "<<ik++<<" : binom\n";
    //}
    long long sum = 0;
    int a, b, c;
    for(int i = 0; i<m; i++){
        cin>>b>>c>>a;
        sum+=a;
        sum%=M;
    }

    long long n2bin = n;
    n2bin *= (n-1);
    n2bin/=2;
    n2bin %= M;

    long long nNums = fastPow(n2bin, k);
    long long orgNums = nNums;

    long long out = 0;
    long long tmp;
    for(long long i = 0; i<k; i++){
        tmp = fastPow(n2bin-1, k-i);
        tmp *= binomials[i];
        tmp%=M;
        nNums = delMod(nNums, tmp);
        out += nNums * ((sum + m * i)%M);
        out %= M;
        //cout<<nNums<<" : "<<binomials[i]<<" : "<<tmp<<" : "<< nNums * (sum + m * i)<< " : "<<out <<" tmp"<<endl;
    }
    //cout<<out<<" :out\n";

    long long div = ext_euc(orgNums, M).first;

    out *= div;
    out%=M;
    cout<<out<<"\n";
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