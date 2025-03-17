#pragma GCC optimize("O2")
#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

vector<pii> all_tiles, to_check;
set<pii> set_blck, used, possible, all_ins;

void add_neighbours(pii pos, vector<pii>& vec){
    pii tmp1 = pos, tmp2 = pos, tmp3 = pos, tmp4 = pos;
    tmp1.first--;
    tmp2.first++;
    tmp3.second--;
    tmp4.second++;

    if(set_blck.find(tmp1) != set_blck.end()) vec.push_back(tmp1);
    if(set_blck.find(tmp2) != set_blck.end()) vec.push_back(tmp2);
    if(set_blck.find(tmp3) != set_blck.end()) vec.push_back(tmp3);
    if(set_blck.find(tmp4) != set_blck.end()) vec.push_back(tmp4);
}

bool check_liftable(pii pos){
    pii tmp1 = pos, tmp2 = pos, tmp3 = pos, tmp4 = pos;
    tmp1.first--;
    tmp2.first++;
    tmp3.second--;
    tmp4.second++;

    bool tmp = (set_blck.find(tmp1) == set_blck.end() | possible.find(tmp1) != possible.end());
    tmp &= (set_blck.find(tmp2) == set_blck.end() | possible.find(tmp2) != possible.end());

    if(tmp) return true;

    tmp = (set_blck.find(tmp3) == set_blck.end() | possible.find(tmp3) != possible.end());
    tmp &= (set_blck.find(tmp4) == set_blck.end() | possible.find(tmp4) != possible.end());

    return tmp;
}

int propagate(){
    int out = 0;

    while(to_check.size()){
        pii tile = to_check.back();
        to_check.pop_back();
        if(used.find(tile) != used.end()) continue;
        if(check_liftable(tile)){
            used.insert(tile);
            possible.insert(tile);
            add_neighbours(tile, to_check);
            out++;
        }
    }

    return out;
}

int count_valid(){
    int out = 0;
    used.clear();
    possible.clear();
    to_check.clear();
    for(pii tile : all_tiles){
        if(set_blck.find(tile) == set_blck.end()) continue;
        if(check_liftable(tile)){
            used.insert(tile);
            possible.insert(tile);
            add_neighbours(tile, to_check);
            out++;
        } 
    }

    out += propagate();

    return out;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n, m, k, q;
    cin>>n>>m>>k>>q;

    for(int i = 0; i<k; i++){
        int a, b;
        cin>>a>>b;

        set_blck.insert({a, b});
        all_ins.insert({a, b});
        all_tiles.push_back({a, b});
    }

    cout<<count_valid()<<endl;

    for(int i = 0; i<q; i++){
        int a, b;
        cin>>a>>b;

        if(set_blck.find({a, b}) == set_blck.end()){
            if(all_ins.find({a, b}) == all_ins.end()){
                all_ins.insert({a, b});
                all_tiles.push_back({a, b});
            }
            set_blck.insert({a, b});
        }else{
            set_blck.erase({a, b});
        }

        cout<<count_valid()<<endl;
    }
    return 0;
}