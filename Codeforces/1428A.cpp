#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll x, y, x1, y1, answ=0;
        cin >> x >> y >> x1 >> y1;
        answ = abs(x1-x) + abs(y1-y);
        if(x1!=x && y1!=y)
            answ+=2;
        cout << answ <<'\n';

    }

    return 0;
}