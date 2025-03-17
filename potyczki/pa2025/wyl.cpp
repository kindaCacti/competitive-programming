#include <bits/stdc++.h>

using namespace std;

bool test(vector<int> numbers){
    bool possible = true;
    for(int i = 1; i<numbers.size()-1; i++){
        if(numbers[i] <= numbers[i-1]) possible = false;
        numbers[i] -= (numbers[i-1] + 1);
    }
    int tmp = numbers[numbers.size() - 2] - numbers[numbers.size() - 1];
    if(tmp != 0 and tmp != -1) possible = false;
    return possible;
}

void solve(){
    int n;
    cin>>n;

    bool sr = false;
    bool possible = true;
    vector<int> numbers;
    for(int i = 0; i<n; i++){
        int a;
        cin>>a;
        if(a == 0 and numbers.size() != 0) sr = true;
        else if(a > 0){
            numbers.push_back(a);
            if(sr) possible = false;
        }
    }

    if(numbers.size() == 1 and numbers[0] > 1) possible = false;
    if(numbers.size() == 2 and abs(numbers[0] - numbers[1]) > 1) possible = false;
    if(numbers.size() > 2){
        bool tmp = test(numbers);
        numbers[0]--;
        tmp |= test(numbers);
        possible &= tmp;
    }

    if(!possible){
        cout<<"NIE\n";
        return;
    }

    cout<<"TAK\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin>>t;

    while(t--) solve();
    return 0;
}