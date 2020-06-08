#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 200005;

int main(){
    vector<ll> suffix(N,0),prefix(N,0),a(N,0);
    ll n, k, x;
    ll mult = 1;
    cin >> n >> k >> x;
    while(k--){
        mult*=x;
    }

    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    for(int i=1;i<=n;i++){
        suffix[i] = suffix[i-1] | a[i];
    }

    for(int i=n;i>0;i--){
        prefix[i] = prefix[i+1] | a[i];
    }

    ll answ = 0;
    for(int i=1;i<=n;i++){
        answ = max(answ, suffix[i-1] | (a[i]*mult) | prefix[i+1]);
    }
    cout << answ << '\n';

    return 0;
}