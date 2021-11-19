#include <bits/stdc++.h>
#define ll long long
#define maxn int(2e5+5)
using namespace std;

tuple<ll,ll,ll> exgcd(ll a, ll b) {
    if (b == 0) return {a, 1, 0};
    ll d, x, y;
    tie(d, x, y) = exgcd(b,a%b);
    return {d, y, x-a/b*y};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    ll base, n;
    vector<ll> arr, pot, potinv;
    ll acm  = 0;
    
    cin >> base >> n;
    arr.assign(n,0);
    for(auto &x:arr)
        cin >> x;
    reverse(arr.begin(),arr.end());

    ll inv, lixo;
    tie(lixo,inv,lixo) = exgcd(base,base+1);

    pot.assign(maxn,0);
    pot[0] = 1;
    for(int i=1;i<maxn;i++){
        pot[i] = (pot[i-1]*base)%(base+1);
    }

    inv = (inv+(base+1))%(base+1);
    potinv.assign(maxn,0);
    potinv[0] = 1;
    for(int i=1;i<maxn;i++){
        potinv[i] = (potinv[i-1]*inv)%(base+1);
    }

    for(int i=0;i<n;i++){
        acm = (acm + arr[i]*pot[i])%(base+1);
    }   
    
    
    pair<int,int> answ = {-1,-1};

    if(acm==0) answ = {0,0};

    for(int i=n-1;i>=0;i--){
        if(answ.first!=-1)   
            break;
        ll total = acm, faltando;
        total = (total - (arr[i])*pot[i])%(base+1); 
        if(total<0)
            total = (total + (base+1))%(base+1);
        faltando = ((base+1)-total)%(base+1);
        faltando = (faltando+(base+1))%(base+1);
        faltando = (faltando*potinv[i])%(base+1);

        if(faltando<base && faltando<arr[i]){
            answ = {n-i,faltando};
        }
    }

    cout << answ.first << " " << answ.second <<  "\n";
    return 0;
}