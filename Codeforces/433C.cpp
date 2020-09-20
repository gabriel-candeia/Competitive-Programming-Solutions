#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, m, answ=0, delta=0;
    vector<ll> arr;
    map<ll,vector<ll>> mp;

    cin >> n >> m;
    arr.assign(m,0);
    for(int i=0;i<m;i++){
        cin >> arr[i];
        if(i) answ+=abs(arr[i]-arr[i-1]);
    }

    for(int i=0;i<m-1;i++)
        if(arr[i]!=arr[i+1]) mp[arr[i]].push_back(arr[i+1]);
    
    for(int i=1;i<m;i++)
        if(arr[i]!=arr[i-1]) mp[arr[i]].push_back(arr[i-1]);
    
    for(auto &p:mp){
        if(!p.second.size()) continue;
        sort(p.second.begin(),p.second.end());
        ll x = p.first, y = p.second[(p.second.size())/2], cmp = 0;
        for(auto v:p.second)
            cmp += abs(v-y)-abs(v-x);
        delta = min(delta,cmp);
    }

    cout << answ+delta <<'\n';

    return 0;
}