#include <bits/stdc++.h>
 
using namespace std;
 
int sgn(long long a){
    if(a<0) return -1;
    if(a>0) return 1;
    return 0;
}
 
int orientation(pair<long long, long long> p1, pair<long long, long long> p2, pair<long long, long long> p3){
    pair<long long, long long> v1, v2;
    v1 = {p1.first-p2.first, p1.second-p2.second};
    v2 = {p1.first-p3.first, p1.second-p3.second};
 
    return sgn(v1.first*v2.second - v1.second*v2.first);
}
 
bool isColinear(pair<long long, long long> p1, pair<long long, long long> p2, pair<long long, long long> p3){
    if(p3.first<=max(p1.first, p2.first) && p3.first >= min(p1.first, p2.first)) 
        if(p3.second <= max(p1.second, p2.second) && p3.second >= min(p1.second, p2.second))
            return true;
    return false;
}
 
void solve(){
    pair<long long, long long> p1, p2, p3, p4;
    cin>>p1.first>>p1.second;
    cin>>p2.first>>p2.second;
    cin>>p3.first>>p3.second;
    cin>>p4.first>>p4.second;
 
    int ori = orientation(p1, p2, p3);
    if(ori==0 && isColinear(p1, p2, p3)){
        cout<<"YES";
        return;
    }
    int ori2 = orientation(p1, p2, p4);
    if(ori2 == 0 && isColinear(p1, p2, p4)){
        cout<<"YES";
        return;
    }
    int ori3 = orientation(p3, p4, p1);
    if(ori3 == 0 && isColinear(p3, p4, p1)){
        cout<<"YES";
        return;
    }
    int ori4 = orientation(p3, p4, p2);
    if(ori4 == 0 && isColinear(p3, p4, p2)){
        cout<<"YES";
        return;
    }
 
    if(ori==0) ori = ori2;
    if(ori2==0) ori2 = ori;
    if(ori3==0) ori3 = ori4;
    if(ori4==0) ori4 = ori3;
 
    //cout<<ori<<" "<<ori2<<" "<<ori3<<" "<<ori4<<" : ori"<<endl;
 
    if(ori!=ori2 && ori3!=ori4){
        cout<<"YES";
        return;
    }
 
    cout<<"NO";
    return;
    
 
}
 
int main(){
    int t;
    cin>>t;
 
    while(t--){
        solve();
        cout<<"\n";
    }
 
 
    return 0;
}