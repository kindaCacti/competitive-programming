#include <bits/stdc++.h>
 
using namespace std;
 
void DFS(int starting, vector<int>*& edges, int n, int*& vals){
    vector<int> queue = {starting};
    int k = 0;
    bool* used = new bool[n]{0};
    int cn, nn;
 
    while(true){
        while(k<queue.size()&&used[queue[k]]) k++;
        if(k>=queue.size()) break;
 
        cn = queue[k];
        used[cn] = 1;
        for(int i = 0; i<edges[cn].size(); i++){
            nn = edges[cn][i];
            if(used[nn]) continue;
            queue.push_back(nn);
            vals[nn] = vals[cn]+1;
        }
    }
}
 
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    vector<int>* edges = new vector<int>[n];
 
    int a, b;
    for(int i = 0; i<n-1; i++){
        cin>>a>>b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
 
    int* vals = new int[n]{0};
    DFS(0, edges, n, vals);
 
    int md = -1, fn;
    for(int i = 0; i<n; i++){
        if(vals[i]>md){
            md = vals[i];
            fn = i;
        }
    }
 
    vals = new int[n]{0};
 
    int out = -1;
    DFS(fn, edges, n, vals);
 
    int sf;
 
    for(int i = 0; i<n; i++){
        if(out<vals[i]){
            out = vals[i];
            sf = i;
        }
    }
 
    int* vals2 = new int[n]{0};
    DFS(sf, edges, n, vals2);
 
    for(int i = 0; i<n; i++){
        cout<<max(vals[i], vals2[i])<<" ";
    }
 
    return 0;
}