#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){ 
    ll t;
    cin >> t;
    while(t--){
        ll n;
        vector<ll> arr;
        vector<vector<ll>> cnt;

        cin >> n; arr.assign(n,0);
        cnt.assign(n+1,vector<ll>(n+1,0));
        for(auto &x:arr)
            cin >> x;
        
        ll answ=0;
        for(ll j=n-1;j>=0;j--){
            for(ll i=j-1;i>=0;i--)
                answ += cnt[arr[i]][arr[j]];
            for(ll i=j+1;i<n;i++)
                cnt[arr[j]][arr[i]]++;
        }

        cout << answ <<'\n';

    }

    return 0;
}