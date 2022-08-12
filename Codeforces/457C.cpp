#include<bits/stdc++.h>
#define ll long long
#define maxn int(1e5+5)
using namespace std;

vector<ll> valores[maxn];
pair<ll,int> ft[maxn];
const ll inf = 1e17;

int lsb(int x){
    return x&(-x);
}

void update(int l, pair<ll,int> v){
    for(;l<maxn;l+=lsb(l)){
        ft[l].first+=v.first, ft[l].second+=v.second;
    }
}

pair<ll,int> get(int l){
    pair<ll,int> answ = {0,0};
    for(;l;l-=lsb(l)){
        answ.first += ft[l].first, answ.second += ft[l].second;
    }
    return answ;
}

ll getMenores(int x){
    int original = x;
    int pos = 0;
    for(int k=25;k>=0;k--){
        if(pos+(1<<k)<maxn && ft[pos+(1<<k)].second<x){
            x -= ft[pos+(1<<k)].second;
            pos += (1<<k);
        }
    }
    pos++;
    auto par = get(pos);
    if(par.second<original){
        return inf;
    }
    return par.first - pos*(par.second-original);
}


int main(){
    ll total = 0, answ, votos;
    int n;

    cin >> n;
    votos = n;
    for(int i=0;i<n;i++){
        ll a, b;
        cin >> a >> b;
        if(a!=0 && b!=0){
            valores[a].push_back(b);
        }
        total += b;
    }

    answ = total;
    vector<int> vivos;
    for(int i=0;i<maxn;i++){
        if(valores[i].size()){
            vivos.push_back(i);
            sort(valores[i].begin(),valores[i].end());
        }
    }
    //cout << votos <<"\n";
    for(int i=0;i<=n;i++){        
        ll k = max(i+1-votos,0ll);
        //cout << i << " "  << votos << " " << k <<  " " << total << " " << getMenores(k)<<"\n";
        answ = min(answ,total+getMenores(k));

        for(auto x:vivos){
            int v = valores[x].back();
            total -= v;
            update(v,{v,1});
            valores[x].pop_back();
            votos--;
        }
        for(int i=0;i<vivos.size();i++){
            while(i<vivos.size() && valores[vivos[i]].size()==0){
                swap(vivos[i],vivos[vivos.size()-1]);
                vivos.pop_back();
            }
        }
    }

    cout << answ <<"\n";

    return 0;
}