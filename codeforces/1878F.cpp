#include <bits/stdc++.h>

using namespace std;

map<int, int> primeDivs;
vector<int> cDivs;
vector<int> erastotenes;
int N = 1e6+7;

void setErastotenes(){
    erastotenes.assign(N, 0);

    for(int i = 2; i*i<N; i++){
        if(erastotenes[i]) continue;
        for(int j = i; j<N; j+=i){
            erastotenes[j] = i;
        }
    }
}

void setPrimeDivs(int k){
    while(k>1){
        if(erastotenes[k] == 0) erastotenes[k] = k;
        int tmp = erastotenes[k];
        if(primeDivs.find(tmp) == primeDivs.end()){
            primeDivs[tmp] = 0;
            cDivs.push_back(tmp);
        }
        primeDivs[tmp]++;
        k /= tmp;
    }
}

bool isDivisible(){
    map<int, int> pd;
    vector<int> cd;

    int k;
    for(int div : cDivs){
        k = primeDivs[div] + 1;
        while(k>1){
            if(erastotenes[k] == 0) erastotenes[k] = k;
            int tmp = erastotenes[k];
            if(pd.find(tmp) == pd.end()){
                pd[tmp] = 0;
                cd.push_back(tmp);
            }
            pd[tmp]++;
            k /= tmp;
        }
    }

    for(int div : cd){
        if(primeDivs.find(div)==primeDivs.end()) return false;
        if(primeDivs[div] < pd[div]) return false;
    }

    return true;
}

long long getNumDivs(){
    long long tmp = 1;
    for(int i = 0; i<cDivs.size(); i++){
        tmp *= (primeDivs[cDivs[i]]+1);
    }

    return tmp;
}

void solve(){
    primeDivs.clear();
    cDivs.clear();
    int n, q;
    cin>>n>>q;

    setPrimeDivs(n);
    int nn = n;
    int a, b;
    for(int i = 0; i<q; i++){
        cin>>a;
        if(a==1){
            cin>>b;
            nn *= b;
            setPrimeDivs(b);
            if(isDivisible()){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
        }
        if(a==2){
            primeDivs.clear();
            cDivs.clear();
            setPrimeDivs(n);
            nn = n;
        }
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    setErastotenes();
    int t;
    cin>>t;

    while(t--){
        solve();
        cout<<"\n";
    }

    return 0;
}