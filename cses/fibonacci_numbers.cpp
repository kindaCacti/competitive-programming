#include <bits/stdc++.h>
 
using namespace std;
 
const int mod = 1e9+7;
 
pair<int, int>* multiply(pair<int, int>* mat1, pair<int, int>* mat2){
    long long x0 = (long long)mat1[0].first*mat2[0].first;
    x0%=mod;
    x0+=(long long)mat1[0].second*mat2[1].first;;
    x0%=mod;
    long long x1 = (long long)mat1[1].first*mat2[0].first;
    x1%=mod;
    x1+=(long long)mat1[1].second*mat2[1].first;;
    x1%=mod;
    long long x2 = (long long)mat1[0].first*mat2[0].second;
    x2%=mod;
    x2+=(long long)mat1[0].second*mat2[1].second;
    x2%=mod;
    long long x3 = (long long)mat1[1].first*mat2[0].second;
    x3%=mod;
    x3+=(long long)mat1[1].second*mat2[1].second;;
    x3%=mod;
 
    //cout<<x0<<":"<<x1<<":"<<x2<<":"<<x3<<"::\n";
    return (new pair<int, int>[2]{{x0,x2},{x1,x3}});
}
 
pair<int, int>* fastPow(pair<int, int>* mat, long long pow){
    if(pow==1){
        return mat;
    }
    pair<int, int>* tmp;
    tmp = fastPow(mat, pow/2);
    tmp = multiply(tmp, tmp);
    if(pow%2) tmp = multiply(tmp,mat);
    return tmp;
}
 
void solve(){
    long long n;
    cin>>n;
    if(n==0){
        cout<<0<<endl;
        return;
    }
    pair<int, int>* mat = new pair<int, int>[2]{{1,1},{1,0}};
    mat = fastPow(mat, n);
    cout<<mat[0].second<<endl;
}
 
int main(){
    int t = 1;
 
    while(t--){
        solve();
    }
 
    return 0;
}