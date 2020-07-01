#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 998244353;

int get_len(int a){
    int cnt=-1;
    while(a){
        a/=10;
        cnt++;
    }
    return cnt;
}

int main(){
    ll n, d;
    vector<ll> a, geq(12,0), lenq(12,0), len;

    cin >> n;
    a.assign(n,0);
    len.assign(n,0);
    for(int i=0;i<n;i++){
        cin >> a[i];
        len[i] = get_len(a[i]);
        geq[len[i]]++;
        lenq[len[i]+1]++;
    }

    for(int i=10;i>=0;i--){
        geq[i]+=geq[i+1];
    }
    
    ll pot=10;
    for(int i=1;i<=10;i++){
        lenq[i]=((lenq[i]*pot)%mod + lenq[i-1])%mod;
        pot = (pot*10ll)%mod;
    }

    pot = 1;
    for(int i=0;i<=10;i++){
        lenq[i]= (lenq[i]*pot)%mod;
        pot = (pot*10ll)%mod;
    }
/*
    for(int i=0;i<=10;i++){
        cout << lenq[i] << ' ';
    }
    cout << '\n';*/


    ll answ = 0;
    for(int i=0;i<n;i++){
        ll cnt=0;
        pot = 1;  
        while(a[i]){
            d = a[i]%10;
            answ = (answ + ((d*(11*(geq[cnt]*pot)%mod)%mod)%mod + 2*(d*lenq[cnt])%mod)%mod)%mod;
            a[i]/=10;
            pot = (pot*100ll)%mod;
            cnt++;
        }
    }
    
    cout << answ << '\n';

    return 0;
}