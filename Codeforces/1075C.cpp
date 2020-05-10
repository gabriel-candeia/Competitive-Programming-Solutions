#include<bits/stdc++.h>
#define ll long long
#define D(x) cout << #x << " = " << x << '\n'
using namespace std;

ll max(ll a, ll b){
    return (a<b) ? b : a;
}

int main(){
    ll n, m, k;
    vector<ll> x(1,1e9), s;
    vector<vector<ll>> hori;
    map<ll,ll> last;
    
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> k;
        x.push_back(k);
    }
    sort(x.begin(),x.end());

    ll a, b, h;
    for(int i=0;i<m;i++){
        cin >> a >> b >> h;
        hori.push_back({a,b,h});
    }

    sort(hori.begin(),hori.end());
    for(int i=0;i<m;i++){
        if(hori[i][0]-last[hori[i][2]]<=1){
            s.push_back(hori[i][1]);
        }
        last[hori[i][2]] = hori[i][1];
    }
    sort(s.begin(),s.end());

    ll cnt=0, best=n+m, ptr=0;
    //D(s.size());
    for(int i=0;i<=n;i++){
        while(ptr<s.size() && s[ptr]<x[i]){
            ptr++;
        }
        cnt = i + (s.size()-ptr);
        best = min(best,cnt);
    }

    cout << best << '\n';

    return 0;
}