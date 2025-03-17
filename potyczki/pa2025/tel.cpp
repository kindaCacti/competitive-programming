#include <bits/stdc++.h>
#pragma GCC optimize("O2")

using namespace std;

vector<vector<int>> dists;
int n;
const int inf = 10000;

void doWarshall(){
    for(int k = 0; k<n; k++){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
            }
        }
    }
}

void solve(){
    srand(time(NULL));
    cin>>n;

    dists.assign(n, vector<int>(n));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            char a;
            cin>>a;
            dists[i][j] = a - '0';
            if(dists[i][j] == 0 and i != j) dists[i][j] = inf;
        }
    }

    int bestWithout = 0;
    doWarshall();

    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            bestWithout = max(bestWithout, dists[i][j]);
        }
    }

    int out = bestWithout;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            bool isgood = true;
            int tmp = 0;

            for(int k = 0; k<n; k++){
                for(int l = k+1; l < n; l++){
                    int v1 = k;
                    int v2 = l;

                    int tt = min(dists[v1][i] + dists[j][v2], dists[v1][j] + dists[i][v2]);
                    tt = min(tt, dists[v1][v2]);
                    tmp = max(tmp, tt);
                    if(tmp >= out){
                        isgood = false;
                        break;
                    }
                }
                if(!isgood) break;
            }
            out = min(out, tmp);
        }
    }

    cout<<out<<endl;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin>>t;

    while(t--) solve();
    return 0;
}