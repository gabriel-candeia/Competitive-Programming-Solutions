#include<bits/stdc++.h>
using namespace std;

int main(){
    int x1, y1, x2, y2, a, l, r;
    int answ = 1e8;

    cin >> x1 >> y1 >> x2 >> y2;
    cin >> a >> l >> r;

    if(x2<x1) swap(x1,x2), swap(y1,y2);
    if(l>r) swap(l,r);

    if(y1<=r && y1>=l && y2<=r && y2>=l && x1<=a && a<=x2){
        //(x1,y1) -> (a,l-1) -> (x2,y1)
        if(l-1>=0){
            answ = min(answ, abs(x2-x1) + abs(l-1-y1) + abs(y2-l+1)) ;
        }
        answ = min(answ, abs(x2-x1) + abs(r+1-y1) + abs(y2-r-1)) ;
    }
    else{
        answ = abs(x2-x1) + abs(y2-y1);
    }

    cout << answ <<"\n";

    return 0;
}