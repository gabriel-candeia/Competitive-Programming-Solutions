#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, m;
    ll a, b;

    vector<ll> h;    
    vector<bool> good;

    cin >> n >> m;
    h.assign(n+1,0);
    good.assign(n+1,true);

    for(int i=1;i<=n;i++){
        cin >> h[i];
    }

    for(int i=0;i<m;i++){
        cin >> a >> b;
        good[a] = good[a] && (h[a]>h[b]);
        good[b] = good[b] && (h[b]>h[a]);
    }

    int cnt=0;
    for(int i=1;i<=n;i++){
        cnt+=good[i];
    }

    cout << cnt << '\n';

    return 0;
}