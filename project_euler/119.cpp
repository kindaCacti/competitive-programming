#include <bits/stdc++.h>

using namespace std;

int sumOfDigits(long long a){
    int out = 0;
    while(a){
        out+=a%10;
        a/=10;
    }
    return out;
}

int main(){
    long long max = 3*1e14;

    vector<long long> nums = {};
    long long t = 2;

    long long tmp;
    for(long long i = 2; i*i<=max; i++){
        t = i*i;
        while(t<=max){
            if(sumOfDigits(t) == i){
                nums.push_back(t);
            }
            tmp = t*i;
            if(tmp/i!=t) break;
            t*=i;
        }
    }

    sort(nums.begin(), nums.end());
    for(long long i : nums){
        cout<<i<<endl;
    }
    cout<<nums.size();

    return 0;
}