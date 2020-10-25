#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll cnt1, cnt2, x, y;
bool isOk(ll v){
    ll onlyX, onlyY, both;
    both =  (v-v/x)+(v-v/y)-(v-v/(x*y));
    onlyX = (v-v/x)-both;
    onlyY = (v-v/y)-both;

    //cout << both <<  " " << onlyY << " " << onlyX << '\n';
    if(onlyX+both>=cnt1){
        if(onlyX<cnt1)
            both = max(both - (cnt1-onlyX),0ll);
        if(onlyY+both>=cnt2)
            return true;
    }
    
    return false;
}


int main(){
    cin >> cnt1 >> cnt2 >> x >> y;

    ll l=1, r = 1e18, med, answ;
    while(l<=r){
        med = l + (r-l)/2;
        if(isOk(med)){
            answ = med;
            r = med-1;
        }
        else{
            l = med+1;
        }
    }
    
    cout << answ << '\n';

    return 0;
}