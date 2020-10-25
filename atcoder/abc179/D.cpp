#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 998244353;
int main(){
    ll n, k, x, y;
    vector<ll> arr, inc;
    vector<pair<ll,ll>> s;

    cin >> n >> k;
    for(int i=0;i<k;i++){
        cin >> x >> y;
        s.push_back({x,y});
    }
    arr.assign(n+5,0);
    inc.assign(n+5,0);

    arr[1] = 1;
    for(int i=1;i<=n;i++){
        inc[i] = (inc[i]+inc[i-1])%mod;
        arr[i] = (arr[i]+inc[i])%mod;
        for(auto p:s){
            if(i+p.first<=n)
                inc[i+p.first]=(inc[i+p.first]+arr[i])%mod;
            if(i+p.second+1<=n)
                inc[i+p.second+1]=((inc[i+p.second+1]-arr[i])%mod+mod)%mod;
        }
    }

    cout << arr[n] <<'\n';

    return 0;
}