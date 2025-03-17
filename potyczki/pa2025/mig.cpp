#include <bits/stdc++.h>

using namespace std;

const int screen_size = 100;

int main(){
    vector<string> screen(screen_size, string(screen_size, '0'));

    screen[0][1] = '1';
    for(int i = 1; i<screen_size; i++) screen[i][0] = '1';

    for(int i = 2; i<screen_size; i++) screen[screen_size-1][i] = '1';
    
    for(int i = 0; i<screen_size; i++){
        if(i <= 2 or i%2 == 0) continue;

        for(int j = 1; j<screen_size; j++) screen[j][i] = '1';
    }

    for(string s : screen) cout<<s<<endl;
    return 0;
}