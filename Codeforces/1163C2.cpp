#include<bits/stdc++.h>
#define ll long long
using namespace std;

pair<ll,ll> normaliza(ll x, ll y){
    if(x==0)
        return {0,1};
    if(y==0)
        return {1,0};
    int d = __gcd(abs(x),abs(y));
    if(y<0)
        return {-x/d,-y/d};
    return {x/d,y/d};
}

pair<ll,ll> desloca(pair<ll,ll> pt, pair<ll,ll> v){
    if(v.first==0) return {pt.first,0};
    ll t = 0;
    if(pt.first>0)
        t = pt.first/v.first;
    else if(pt.first<0){
        if(v.first>0)
            t = pt.first/v.first -((abs(pt.first)%abs(v.first))!=0);
        if(v.first<0)
            t = pt.first/v.first +((abs(pt.first)%abs(v.first))!=0);
    }
    return {pt.first-t*v.first,pt.second-t*v.second};
}

int main(){
    ll n, x, y, answ, retas;
    vector<pair<ll,ll>> pt;
    map<pair<ll,ll>,set<pair<ll,ll>>> mp;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x >> y;
        pt.push_back({x,y});
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            auto d = normaliza(pt[i].first-pt[j].first,pt[i].second-pt[j].second);
            mp[d].insert(desloca(pt[i],d));
        }
    }

    retas = answ = 0;
    for(auto p:mp){
        ll qtd = p.second.size();
        retas += qtd;
        answ -= ((qtd)*(qtd-1))/2;
    }
    answ += (retas*(retas-1))/2;
    cout << answ <<"\n";
    return 0;
}