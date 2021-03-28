#include<bits/stdc++.h>
#define maxn int(3e5+5)
#define ll long long
using namespace std;

const int block = sqrt(maxn)+1;
ll n, m, u;

ll cnt(vector<pair<ll,int>> &arr, int v){
    ll l = 0, r = arr.size()-1, answ = -1, med;

    while(l<=r){
        med = l + (r-l)/2;
        if(arr[med].first<v){
            answ = med, l = med+1;
        }
        else{
            r = med-1;
        }
    }

    return answ+1;
}


int main(){
    vector<vector<pair<ll,int>>> arr(sqrt(maxn)+1);
    cin >> n >> m >> u;

    for(int i=0, x;i<n;i++){
        cin >> x;
        arr[i/block].push_back({x,i});
    }

    for(auto &x:arr)
        sort(x.begin(),x.end());

    ll l, r, v, pos;
    for(int i=0;i<m;i++){
        cin >> l >> r >> v >> pos; l--, r--, pos--;
        ll bl = l/block, br = r/block, answ = 0, bp = pos/block;

        for(auto p:arr[bl])
            answ += (p.second>=l && p.second<=r && p.first<v);
        for(int i=bl+1;i<=br-1;i++)
            answ += cnt(arr[i],v);
        if(bl!=br) 
            for(auto p:arr[br])
                answ += (p.second>=l && p.second<=r && p.first<=v);
        
        for(auto &p:arr[bp]){
            if(p.second==pos){
                p.first = (u*answ)/(r-l+1);
                break;
            }
        }
        sort(arr[bp].begin(),arr[bp].end());
    }

    vector<ll> answ(n,0);
    for(auto x:arr)
        for(auto y:x)
            answ[y.second] = y.first;

    for(auto x:answ)
        cout << x << "\n";

    return 0;
}