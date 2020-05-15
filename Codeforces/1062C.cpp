#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = int(1e9)+7;

ll binpow(ll a, ll b, ll mod){
    if(b==0){
        return 1;
    }
    ll temp = binpow(a,b/2,mod);
    if(b%2){
        return ((temp*temp)%mod*a)%mod;
    }
    return (temp*temp)%mod;
}

int main(){
    int n, q, l, r;
    vector<int> arr;
    char a;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    arr.assign(n+1,0);
    for(int i=1;i<=n;i++){
        cin >> a;
        arr[i] = a-'0'+arr[i-1];
    }

    int n1, n0;
    ll answ=0;
    while(q--){
        cin >> l >> r;

        n1 = arr[r]-arr[l-1];
        n0  = (r-l+1) - n1;

        answ = (binpow(2,n0+n1,mod)-binpow(2,n0,mod))%mod;
        if(answ<0){
            answ+=mod;
        }

        cout << answ  << '\n';
    }

    return 0;
}