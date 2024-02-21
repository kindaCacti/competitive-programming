#include <bits/stdc++.h>

using namespace std;

int n;
bool done1 = false, done0 = false;
pair<int, int> cpos0 = {1,1}, cpos1 = {1, 2};

void placeColor(int a){
    if(done1){
        cout<<((a==1)?3:1)<<" "<<cpos0.first<<" "<<cpos0.second<<endl;
        while(true){
            cpos0.second++;
            if(cpos0.second > n){
                cpos0.first++;
                cpos0.second = 1;
            }
            if((cpos0.first ^ cpos0.second)%2 == 0) break;
        }
        if(cpos0.first > n) done0 = true;
        return;
    }
    if(done0){
        cout<<((a==2)?3:2)<<" "<<cpos1.first<<" "<<cpos1.second<<endl;
        while(true){
            cpos1.second++;
            if(cpos1.second > n){
                cpos1.first++;
                cpos1.second = 1;
            }
            if((cpos1.first ^ cpos1.second)%2) break;
        }
        if(cpos1.first > n) done1 = true;
        return;
    }
    if(a != 1){
        cout<<1<<" "<<cpos0.first<<" "<<cpos0.second<<endl;
        while(true){
            cpos0.second++;
            if(cpos0.second > n){
                cpos0.first++;
                cpos0.second = 1;
            }
            if((cpos0.first ^ cpos0.second)%2 == 0) break;
        }
        if(cpos0.first > n) done0 = true;
    }else{
        cout<<2<<" "<<cpos1.first<<" "<<cpos1.second<<endl;
        while(true){
            cpos1.second++;
            if(cpos1.second > n){
                cpos1.first++;
                cpos1.second = 1;
            }
            if((cpos1.first ^ cpos1.second)%2) break;
        }
        if(cpos1.first > n) done1 = true;
    }
}

int main(){
    cin>>n;

    int a;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>a;
            placeColor(a);
        }
    }

    return 0;
}