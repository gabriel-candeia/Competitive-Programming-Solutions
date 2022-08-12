#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n, k;
ll count(ll x){
    ll acm = 0, pow = 1, lo = x;
    while(x<=n){
        acm += pow;
        lo = 2*lo;
        x = 2*x+1;
        pow = 2*pow;
    }
    acm +=  max(n-lo+1,0ll);
    return acm;
}

ll bbOdd(){
    ll l = 1, r = n, answ=-1, med;
    while(l<=r){
        med = (l+r)/2;
        if(count(2*med-1)>=k){
            answ = 2*med-1;
            l = med+1;
        }
        else{
            r = med-1;
        }
    }
    return answ;
}

ll bbEven(){
    ll l = 1, r = n, answ=-1, med;
    while(l<=r){
        med = (l+r)/2;
        if(count(med)-1>=k){
            answ = 2*med;
            l = med+1;
        }
        else{
            r = med-1;
        }
    }
    return answ;
}

int main(){

    cin >> n >> k;
    //cout << count(3) <<"\n";
    cout << max(bbEven(),bbOdd()) <<"\n";

    return 0;
}
