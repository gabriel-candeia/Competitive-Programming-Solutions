#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll comp = 1e9+1;
ll ceil(ll a, ll b){
    return a/b + (a%b!=0);
}

int main(){
    ll n, a, b;
    vector<ll> arr, dir, dist[2];
    ll cntleft = 0;

    cin >> n >> a >> b;

    dist.assign(n,0), dir.assign(n,0);
    for(auto &x:arr) cin >> x;
    for(auto &x:dir) cin >> x, cntleft += (1-x);

    for(int i=0;i<n;i++){
        dist[dir[i]] = arr[i];
    }
    sort(dist[0].rbegin(),dist[0].rend());
    sort(dist[1].begin(),dist[1].end());

    ll ciclos = min(a/n,b/n), tempo;
    
    a = max(a-ciclo*n,0), b = max(b-ciclo*n,0);

    if(!(a==0 || b==0)){
        if(a-cntleft<0){
            for(int i=0;i<abs(a-cntleft) && dist[0].size();i++)
                dist[0].pop_back();
        }
        a-=cntleft;
        a = max(a,0);
        if(b-(n-cntleft)<=0){
            for(int i=0;i<abs(b-(n-cntleft)) && dist[1].size();i++)
                dist[1].pop_back();
        }
        b-=(n-cntleft);
        b=max(b,0);
        cntleft = dist[0].size();
        if(a-(n-cntleft)<=0){
            for(int i=0;i<abs(a-(n-cntleft)) && dist[1].size();i++)
                dist[1].pop_back();
        }
        a-=(n-cntleft);
        a = max(a,0);
        if(b-cntleft<=0){
            for(int i=0;i<abs(b-cntleft) && dist[0].size();i++)
                dist[0].pop_back();
        }
        b-=cntleft;
        b = max(b,0);
        cntleft = dist[0].size();
    }

    for(auto x:)

    return 0;
}