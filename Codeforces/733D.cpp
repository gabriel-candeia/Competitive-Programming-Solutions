#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pll pair<ll,ll>
using namespace std;
//Please, don't judge me for this problem. This one is specially crap.

int main(){
    ll n, x[3];
    map<pll,pair<pll,pll>> mp;
    
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> x[0] >> x[1] >> x[2];
        for(int j=0;j<3;j++){
            for(int k=j+1;k<3;k++){
                pair<pll,pll> &p = mp[{min(x[j],x[k]),max(x[j],x[k])}];
                if(p.second.first==i)
                    continue;
                if(p.second.first==0)
                    p = {{0,0},{i,x[3^k^j]}};
                else if(p.second.second <= x[3^k^j]){
                    p.first = p.second;
                    p.second = {i,x[3^k^j]};
                }
                else if(p.first.second <= x[3^k^j])
                    p.first = {i,x[3^k^j]};
            }
        }
    }

    pll answ;
    ll raio, mx = 0; 

    for(auto p:mp){
        raio = min(p.first.first,p.second.first.second+p.second.second.second);
        if(raio>mx){
            mx = raio;
            answ = p.first;
        }
    }

    set<ll> s;
    if(mp[answ].first.first)
        s.insert(mp[answ].first.first); 
    s.insert(mp[answ].second.first);
    cout << s.size() <<'\n';
    for(auto i : s)
        cout << i << " ";
    cout <<'\n';

    return 0;
}