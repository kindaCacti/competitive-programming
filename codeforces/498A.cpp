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
 
bool solve(int sx, int sy, int ex, int ey){
    pair<long long, long long> p1, p2, p3, p4;
    long long a, b, c;
    cin>>a>>b>>c;

    long long ny = ((-a)*(-1*1e6 - 1) - c);
    p3 = {-1*1e6 - 1, ny};
    ny = ((-a)*(1*1e6 + 1) - c);
    p4 = {1*1e6 + 1, ny};

    p1 = {sx, sy * b};
    p2 = {ex ,ey * b};

 
    int ori = orientation(p1, p2, p3);
    if(ori==0 && isColinear(p1, p2, p3)){
        return 1;
    }
    int ori2 = orientation(p1, p2, p4);
    if(ori2 == 0 && isColinear(p1, p2, p4)){
        return 1;
    }
    int ori3 = orientation(p3, p4, p1);
    if(ori3 == 0 && isColinear(p3, p4, p1)){
        return 1;
    }
    int ori4 = orientation(p3, p4, p2);
    if(ori4 == 0 && isColinear(p3, p4, p2)){
        return 1;
    }
 
    if(ori==0) ori = ori2;
    if(ori2==0) ori2 = ori;
    if(ori3==0) ori3 = ori4;
    if(ori4==0) ori4 = ori3;
 
    if(ori!=ori2 && ori3!=ori4){
        return 1;
    }
 
    return 0;
}
 
int main(){
    int t;

    int sx, sy, ex, ey;
    cin>>sx>>sy>>ex>>ey;
    cin>>t;
    int out = 0;
    while(t--){
        out += solve(sx, sy, ex, ey);
    }

    cout<<out;
    return 0;
}