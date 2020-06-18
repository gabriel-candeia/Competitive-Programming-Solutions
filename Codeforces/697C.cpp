#include<bits/stdc++.h>
#define ll long long
using namespace std;

map<ll,ll> totalCost;

void formPath(ll u, ll v, ll w){
    ll mx = max(u,v), mn = min(u,v), temp, top=0;
    ll arr[300];
    while(mx!=mn){
        totalCost[mx]+=w;
        mx = mx>>1;
        if(mx<mn){
            temp = mx;
            mx = mn;
            mn = temp;
        }
    }
}

ll pathCost(ll u, ll v){
    ll mx = max(u,v), mn = min(u,v), temp, cost=0;
    while(mx!=mn){
        cost+=totalCost[mx];
        mx = mx>>1;
        if(mx<mn){
            temp = mx;
            mx = mn;
            mn = temp;
        }
    }
    return cost;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll op, v, u, w, q;

    cin >> q;
    while(q--){
        cin >> op >> u >> v;
        if(op==1){
            cin >> w;
            formPath(u,v,w);
        }
        else{
            cout << pathCost(u,v) << '\n';
        }
    }
    return 0;
}