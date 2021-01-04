#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll n, m;

ll binpow(ll x, ll y){
    ll ans = 1;
    while(y){
        if(y&1) ans *= x;
        x *= x;
        y >>= 1;
    }
    return ans;
}

int main(){
    cin >> n >> m;
    ll raiz = sqrt(m), answ=1;
    for(int i = 2; i <= raiz; i++){
        int cnt = 0;
        while(m%i == 0){
            cnt++;
            m /= i;
        }
        answ = answ*(binpow(i,cnt/n));
    }
    if(m != 1){
        answ = answ*(binpow(m,1/n));
    }
    
    cout << answ <<'\n';
    return 0;
}
