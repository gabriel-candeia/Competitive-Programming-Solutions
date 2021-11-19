#include<bits/stdc++.h>
#define ll long long
#define ld double
using namespace std;

ld dist(pair<ld,ld> a, pair<ld,ld> b){
    return sqrt((a.first-b.first)*(a.first-b.first)+ (a.second-b.second)*(a.second-b.second));
}

pair<ld,ld> f1(pair<ll,ll> p, ll a, ll b, ll c){
    ll x = p.first;
    return {x,(-x*a-c)/(1.0*b)};
}

pair<ld,ld> f2(pair<ll,ll> p, ll a, ll b, ll c){
    ll y = p.second;
    return {(-y*b-c)/(1.0*a),y};
}

int main(){
    ld answ;
    ll a, b, c;
    pair<ll,ll> p1, p2;
    vector<pair<ld,ld>> v1, v2; 
    
    cin >> a >> b >> c;
    cin >> p1.first >> p1.second >> p2.first >> p2.second;

    answ = (abs(p1.first-p2.first)+abs(p1.second-p2.second));

    if(b) v1.push_back(f1(p1,a,b,c)), v2.push_back(f1(p2,a,b,c));
    if(a) v1.push_back(f2(p1,a,b,c)), v2.push_back(f2(p2,a,b,c));
    
    for(auto u:v1){
        for(auto v:v2){
            answ = min(answ,dist(p1,u)+dist(u,v)+dist(v,p2));
        }
    }

    cout << fixed << setprecision(10) << answ <<'\n';

    return 0;
}