#include<bits/stdc++.h>
#define ll long long
#define maxn int(2e5+5)
using namespace std;

ll ft[maxn];

ll lsone(ll x){
    return x&(-x);
}

void update(ll r, ll v){
    if(r==0) return;
    for(;r<maxn;r+=lsone(r))
        ft[r]+=v;
}

ll get(ll r){
    ll sum = 0;
    for(;r;r-=lsone(r))
        sum+=ft[r];
    return sum;
}

ll get(ll l, ll r){
    return get(r)-get(l-1);
}

int main(){
    ll h, w, m, x, y;
    vector<pair<ll,ll>> arr;

    cin >> h >> w >> m;
    for(int i=0;i<m;i++){
        cin >> x >> y;
        arr.push_back({x,y});
    }

    vector<ll> minl(h+1,w+1), minc(w+1,h+1);
    for(int i=0;i<m;i++){
        minl[arr[i].first] = min(minl[arr[i].first],arr[i].second);
        minc[arr[i].second] = min(minc[arr[i].second],arr[i].first);
    }


    ll answ = 0;
    for(int i=1;i<minc[1];i++){
        answ += minl[i]-1;
    }

    vector<pair<ll,ll>> processar;
    for(int i=1;i<minl[1];i++){
        processar.push_back({minc[i],i});
    }
    
    int ptr = 1;
    sort(processar.begin(),processar.end());
    for(int i=1;i<((int)processar.size());i++){
        while(ptr<minc[1] && ptr<processar[i].first){
            update(minl[ptr],1);
            ptr++;
        }
        answ += minc[processar[i].second]-1-get(processar[i].second,maxn);
    }

    cout << answ << "\n";

    return 0;
}
