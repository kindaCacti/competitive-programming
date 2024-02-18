#include <bits/stdc++.h>

using namespace std;

vector<int> primes;
vector<bool> er;
int N = 100;

void setEr(){
    for(int i = 2; i*i<=N; i++){
        if(er[i]) continue;
        for(int j = i*i; j<=N; j+=i){
            er[j] = 1;
        }
    }

    for(int i = 2; i<=N; i++){
        if(er[i]) continue;
        primes.push_back(i);
    }
}

int main(){
    er.assign(N+1, 0);
    setEr();

    
    return 0;
}