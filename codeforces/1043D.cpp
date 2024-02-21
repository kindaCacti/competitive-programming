#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> vals;
vector<int> bval;
int n, m;

bool canDo(int cval, int sval, int space){
    for(int i = 0; i<m; i++){
        //cout<<sval<<" "<<cval<<" "<<vals[sval][i]<<" "<<vals[cval][i]<<endl;
        if(vals[cval][i] - vals[sval][i] != space) return false;
    }
    return true;
}

long long bin(int a){
    long long tmp = a + 1;
    tmp *= (tmp-1);
    //cout<<a<<" : "<<tmp/2<<endl;
    return (tmp/2);
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>m;

    bval.assign(n, 0);
    vals.assign(n, {});

    int a;

    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cin>>a;
            a--;
            vals[a].push_back(j);
            if(i==0) bval[j] = a;
        }
    }

    long long combs = 0;
    int sp, ep, tmp = 0;
    for(int i = 0; i<n; i++){
        if(tmp==0) sp = i;
        if(!canDo(bval[i], bval[sp], tmp)){
            //cout<<tmp<<" "<<i<<":t"<<endl;
            combs += bin(tmp);
            tmp = 0;
            i--;
        }else{
            tmp++;
        }
    }
    combs += bin(tmp);

    cout<<combs;

    return 0;
}