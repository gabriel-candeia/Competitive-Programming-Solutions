#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

pair<ll,ll> normaliza(ll x, ll y){
    if(x==0)
        return {y/abs(y),0};
    if(y==0)
        return {0,x/abs(x)};
    ll d = __gcd(abs(x),abs(y));
    return {y/d,x/d};
}

int quadrante(const pair<ll,ll>& p){
    if(p.first<=0 && p.second<=0){
        return 1;
    }
    else if(p.first<=0 && p.second>=0){
        return 2;
    }
    else if(p.first>=0 && p.second>=0){
        return 3;
    }
    else if(p.first>=0 && p.second<=0){
        return 4;
    }
}

bool comparator(const pair<pair<ll,ll>,ll>& p1,const pair<pair<ll,ll>,ll>& p2){
    int q1 = quadrante(p1.first), q2 = quadrante(p2.first);
    if(q1!=q2)
        return q1<q2;
    else{
        return p1.first.first*p2.first.second < p2.first.first*p1.first.second;
    }
    
}

ll pot = 10000000000;

int main(){
    ll n;
    map<pair<ll,ll>,ll> mp;
    vector<pair<pair<ll,ll>,ll>> planetas;

    cin >> n;
    for(int i=0;i<n;i++){
        ll x, y, a, s;
        cin >> x >> y >> a >> s;
        mp[normaliza(x,y)]+=a-s;
    }

   for(auto p:mp){
        planetas.push_back({p.first,p.second});
    }
    sort(planetas.begin(),planetas.end(),comparator);
    ll answ = 0, acm = 0, acmmin=0, mn=0, soma=0;
    n = planetas.size();
    
    for(int i=0;i<n;i++){
        int u = i%n;

        acm = max(planetas[u].second,acm+planetas[u].second);
        acmmin = min(planetas[u].second,acmmin+planetas[u].second);
        soma+=planetas[u].second;
        
        mn = min(mn,acmmin);
        answ = max(acm,answ);
    }

    cout << max(answ,soma-mn) <<'\n';
    return 0;
}