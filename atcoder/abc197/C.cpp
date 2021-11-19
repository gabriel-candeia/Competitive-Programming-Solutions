#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll teste(ll msk, vector<ll> &arr){
    ll i = 0, last, answ = 0;
    while(i<arr.size()){
        last = msk%2;
        ll acm = 0;
        while(i<arr.size() && msk%2==last){
            acm |= arr[i++];
            msk/=2;
        }
        answ ^= acm;
    }   
    return answ;
}

int main(){
    ll n;
    vector<ll> arr;

    cin >> n;
    arr.assign(n,0);
    for(auto &x:arr)
        cin >> x;

    ll answ = int(1e18);
    for(ll i=0;i<(1<<n);i++)
        answ = min(teste(i,arr),answ);
    
    cout << answ <<'\n';
    return 0;
}