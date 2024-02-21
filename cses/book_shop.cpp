#include <iostream>
 
using namespace std;
 
int main(){
    int n, x;
    cin>>n>>x;
 
    int* pages = new int[x+1]{0};
 
    pair<int, int>* books = new pair<int, int>[n];
    int a, b;
    for(int i = 0; i<n; i++){
        cin>>a;
        books[i].second = a;
    }
    for(int i = 0; i<n; i++){
        cin>>a;
        books[i].first = a;
    }
    int out = 0;
    for(int i = 0; i<n; i++){
        a = books[i].first;
        b = books[i].second;
        for(int j = x; j>=0; j--){
            if(j-b<0) continue;
            if(pages[j-b]>0||j-b==0){
                pages[j] = max(pages[j], pages[j-b]+a);
                out = max(out, pages[j]);
            }
        }
    }
 
    cout<<out;
 
    return 0;
}
