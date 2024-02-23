#include <bits/stdc++.h>

using namespace std;

long long M = 1e9+7;
long long logn = 23;

vector<vector<long long>> mxr, mnr;
vector<long long> slimes, sum;
long long n;

long long checkSum(long long s, long long e){
    long long tmp = sum[e];
    tmp -= sum[s-1];
    return tmp;
}

bool hasDifferent(long long s, long long e){
    long long cmn = M, cmx = -1, sz = e-s+1;
    //if(sz==1) return true;

    long long pow = 0;
    long long add = 1;
    long long cp = s;
    while(sz){
        if(sz%2){
            cmn = min(cmn, mnr[cp][pow]);
            cmx = max(cmx, mxr[cp][pow]);
            cp += add;
        }
        sz/=2;
        pow++;
        add *= 2;
    }
    //cout<<s<<" : "<<e<<" -> "<<cmn<<" <= "<<cmx<<endl;
    return (cmn<cmx);
}

long long chl(long long a){
    //cout<<"HI2\n";
    if(a==0) return M;
    if(slimes[a] < slimes[a-1]) return 1;
    long long mn = 0, mx = a-1, mid;
    long long na = a-1;

    while(mn<mx){
        //cout<<"l: "<<a<<" "<<mn<<" : "<<mx<<endl;
        mid = (mx + mn)/2 + 1;
        if(hasDifferent(mid, na) and checkSum(mid+1, na+1) > slimes[a]){
            mn = mid;
            continue;
        }
        mx = mid - 1;
    }
    //cout<<"l: "<<a<<" "<<mn<<" : "<<mx<<endl;
    //cout<<"l: "<<hasDifferent(mn, na) << (checkSum(mn+1, na+1) > slimes[a])<<endl;
    if(hasDifferent(mn, na) and checkSum(mn+1, na+1) > slimes[a]) return a-mn;
    return M;
}

long long chr(long long a){
    //cout<<"HI\n";
    if(a==n-1) return M;
    if(slimes[a] < slimes[a+1]) return 1;
    long long mn = a+1, mx = n-1, mid;
    long long na = a+1;

    while(mn<mx){
        mid = (mx + mn)/2;
        //cout<<"r: "<<a<<" "<<mn<<" : "<<mx<<" : "<<mid<<endl;
        if(hasDifferent(na, mid) and checkSum(na+1, mid+1) > slimes[a]){
            mx = mid;
            continue;
        }
        mn = mid + 1;
    }

    //cout<<"r: "<<a<<" "<<mn<<" : "<<mx<<" :e "<<mid<<" :s "<<checkSum(a+1, mn+1)<<endl;

    //cout<<"r: "<<(hasDifferent(na, mn) and checkSum(na+1, mn+1) > slimes[a])<<endl;
    if(hasDifferent(na, mn) and checkSum(na+1, mn+1) > slimes[a]) return mn-a;
    return M;
}

void solve(){
    cin>>n;

    slimes.assign(n, 0);
    mxr.assign(n, {});
    mnr.assign(n, {});
    sum.assign(n+1, 0);

    long long a;
    for(long long i = 0; i<n; i++){
        mxr[i].assign(logn, 0);
        mnr[i].assign(logn, 0);
        cin>>a;
        slimes[i] = a;
        mnr[i][0] = a;
        mxr[i][0] = a;
        sum[i+1] = sum[i] + a;
    }

    for(long long i = 1; i<logn; i++){
        mnr.back()[i] = mnr.back()[0];
        mxr.back()[i] = mxr.back()[0];
    }
    long long pow = 1;
    for(long long j = 1; j<logn; j++){
        for(long long i = 0; i<n-1; i++){
            long long tmp = min(n-1, i+pow);
            mnr[i][j] = min(mnr[tmp][j-1], mnr[i][j-1]);
            mxr[i][j] = max(mxr[tmp][j-1], mxr[i][j-1]);
        }
        pow *= 2;
    }

    for(long long i = 0; i<n; i++){
        long long tout = min(chl(i), chr(i));
        if(tout==M){
            cout<<"-1 ";
            continue;
        }else{
            cout<<tout<<" ";
        }
    }

    cout<<"\n";
}

int main(){
    long long t = 1;

    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}