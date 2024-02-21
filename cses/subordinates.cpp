#include <bits/stdc++.h>
 
using namespace std;
 
int* vals;
 
void fillV(int cn, vector<int>*& edges){
    vals[cn] += edges[cn].size();
    int nn;
    for(int i = 0; i<edges[cn].size(); i++){
        nn = edges[cn][i];
        fillV(nn, edges);
        vals[cn] += vals[nn];
    }
}
 
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin>>n;
 
    vals = new int[n]{0};
    vector<int>* edges = new vector<int>[n];
 
    int a;
    for(int i = 1; i<n; i++){
        cin>>a;
        a--;
        edges[a].push_back(i);
    }
 
    fillV(0, edges);
 
    for(int i = 0; i<n; i++){
        cout<<vals[i]<<" ";
    }
    
}