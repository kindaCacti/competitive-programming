#include <bits/stdc++.h>

using namespace std;

vector<int> genNums(string a){
    int tmp = 0;
    vector<int> out;
    int mul = 1;
    for(int i = 0; i<a.size(); i++){
        if(a[i]==','){
            out.push_back(tmp);
            tmp = 0;
            mul = 1;
            continue;
        }
        if(a[i]=='-'){
            mul = -1;
            continue;
        }
        tmp*=10;
        tmp += (a[i]-'0')*mul;
    }
    out.push_back(tmp);
    return out;
}

int sgn(int a){
    if(a==0) return 0;
    if(a<0) return -1;
    return 1;
}

int isLeft(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3){
    pair<int, int> v1, v2;
    v1 = {p1.first - p2.first, p1.second - p2.first};
    v2 = {p1.first - p3.first, p1.second - p3.second};

    int tmp = p1.first*p2.second-p1.second*p2.first;
    return sgn(tmp);
}

int main(){
    ifstream fin;
    fin.open("./triangles.txt");

    string a;
    vector<int> tmp;
    int b, c, d;
    int out = 0;
    while(fin>>a){
        tmp = genNums(a);
        b = isLeft({tmp[0], tmp[1]}, {tmp[2], tmp[3]}, {0,0});
        c = isLeft({tmp[2], tmp[3]}, {tmp[4], tmp[5]}, {0,0});
        d = isLeft({tmp[4], tmp[5]}, {tmp[0], tmp[1]}, {0,0});
        if(d==b and b==c){
            out++;
        }
    }

    cout<<out;

    return 0;
}