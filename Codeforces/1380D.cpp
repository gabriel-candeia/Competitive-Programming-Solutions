#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll min(ll a, ll b){
    return (a<b) ? a : b;
}

int main(){
    ll n, m, x, k, y;
    vector<ll> a, b, mx;
    vector<pair<ll,ll>> interval;
    bool poss = true;
    ll answ=0;
    
    cin >> n >> m >> x >> k >> y;
    a.assign(n,0);
    b.assign(m,0);

    for(ll i=0;i<n;i++){
        cin >> a[i];
    }

    for(ll i=0;i<m;i++){
        cin >> b[i];
    }

    ll ptr=0, last = 0;
    for(ll i=0;i<n;i++){
        if(ptr<m && a[i]==b[ptr]){
            ptr++;
            interval.push_back({last,i-1});
            last = i+1;
        }
    }
    interval.push_back({last,n-1});

    poss = (ptr==m);
    for(ll i=0;i<interval.size();i++){
        ll l=-1, r = -1, siz = interval[i].second-interval[i].first+1;
        if(interval[i].first){
            l  = a[interval[i].first-1];
        }
        if(interval[i].second+1<n){
            r = a[interval[i].second+1];
        }
        ll mx = -1;
        for(ll j=interval[i].first;j<=interval[i].second;j++){
            mx = max(mx,a[j]);
        }
        if(mx>l && mx>r){
            if(siz<k){
                poss = false;
            }
            else{
                answ += min(1ll*x*(siz/k)+1ll*y*(siz%k),1ll*y*(siz-k) + 1ll*x );
            }   
        }
        else{
            answ += min(1ll*x*(siz/k)+y*(siz%k),1ll*y*siz);
        }
        //cout << l << " " << siz << " " << r << " " << min(x*(siz/k)+y*(siz%k),y*siz) << '\n';
    }
    
    if(poss){
        cout << answ << '\n';
    }
    else{
        cout << -1 << '\n';
    }
    return 0;
}