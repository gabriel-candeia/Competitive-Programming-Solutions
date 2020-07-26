#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 1e9+7;

ll min(ll a, ll b){
    return (a<b) ? a : b;
}

ll max(ll a, ll b){
    return (a>b) ? a : b;
}

int main(){
    ll n, m, a, b;
    map<ll,ll> mp;
    vector<pair<int,int>> bus;

    cin >> n >> m;
    for(ll i=0;i<m;i++){
        cin >> a >> b;
        bus.push_back({b,a});
        mp[a] = mp[b] = 1;
    }
    sort(bus.begin(),bus.end());

    mp[0]=mp[n]=1;
    ll i=0, qtd=0;
    for(auto p:mp){
        mp[p.first] = i++;  
        qtd++;
    }
    ll acm=0;
    int last=0;
    vector<ll> cnt(qtd+2,0), sum(qtd+2,0);
    cnt[0] = 1;
    sum[0] = 0;

    last = 0;
    for(auto p:bus){
        ll l = mp[p.second], r = mp[p.first];
        while(last!=r){
            sum[last+1] = ((sum[last]+cnt[last])%mod+mod)%mod;
            last++;
        }
        cnt[r] = ((cnt[r] + sum[r]-sum[l])%mod+mod)%mod;

        sum[r+1] = ((sum[r]+cnt[r])%mod+mod)%mod;
        last = r;
    }

    /*for(int i=0;i<qtd;i++){
        cout << cnt[i] << " ";
    }cout << '\n';  

    for(int i=0;i<qtd;i++){
        cout << sum[i] << " ";
    }cout << '\n';  */

    cout << cnt[mp[n]] << "\n";
        
    return 0;
}