pair<long long, long long> ext_euc(long long a, long long b){
    if(a==0) return {0, 1};
    pair<long long, long long> tmp = ext_euc(b%a, a);
    long long tp = tmp.second - (b/a) * tmp.first;

    return {tp, tmp.first};
}