#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    cin.tie(0)->sync_with_stdio(0);

    int n, m, s;
    cin>>n>>m>>s;

    vector<pair<int, int>> intervals;
    for(int i = 0; i<m; i++){
        int a, b;
        cin>>a>>b;
        intervals.push_back({a, b});
    }

    sort(intervals.begin(), intervals.end());

    vector<pair<int, int>> final_intervals;
    for(auto pa : intervals){
        if(final_intervals.size() == 0) final_intervals.push_back(pa);
        else{
            if(final_intervals.back().second + 1 == pa.first) final_intervals.back().second = pa.second;
            else final_intervals.push_back(pa);
        }
    }

    for(auto pa : final_intervals){
        if(pa.first <= s and pa.second >= s){
            if((abs(s-pa.first)+1 <= abs(s-pa.second)+1 and pa.first != 1) or pa.second == n){
                cout<<pa.first-1<<endl;
            }else{
                cout<<pa.second + 1<<endl;
            }
            return 0;
        }
    }

    cout<<s<<endl;
    return 0;
}