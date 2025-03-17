#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pii pair<int, int>

struct BlockTower{
    vector<int> lastOfColor;
    vector<pii> buffer;
    int bestOverall;

    void setup(int siz){
        lastOfColor.assign(siz+1, 0);
        bestOverall = 0;
    }

    void addBlock(int a, int w, int c){
        int tmp = max(lastOfColor[w] + a, bestOverall + a - c);
        buffer.push_back({tmp, w});
    }

    void flush_buffer(){
        while(buffer.size()){
            lastOfColor[buffer.back().second] = max(lastOfColor[buffer.back().second], buffer.back().first);
            bestOverall = max(bestOverall, buffer.back().first);
            buffer.pop_back();
        }
    }
}bt;

signed main(){
    cin.tie(0)->sync_with_stdio(0);

    int n, c; cin>>n>>c;

    bt.setup(500005);

    int la = -1;
    for(int i = 0; i<n; i++){
        int a, w;
        cin>>a>>w;

        if(la != a) bt.flush_buffer();
        la = a;

        bt.addBlock(a, w, c);
    }

    bt.flush_buffer();

    cout<<bt.bestOverall<<endl;
    return 0;
}