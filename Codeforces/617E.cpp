#include<bits/stdc++.h>
#define block 500
#define ll long long
using namespace std;

struct query{
    ll l, r, id;

    query(ll l, ll r, ll id){
        this->l = l, this->r = r, this->id = id;
    }

    bool operator<(query x){
        return  pair<ll,ll>{l/block, r} < pair<ll,ll>{x.l/block, x.r};
    }
};


int main(){
    ll n, m, k;
    vector<ll> arr, answ;
    vector<query> queries;
    vector<ll> mp(int(1e7+6),0);

    cin >> n >> m >> k;
    arr.assign(n+1,0);
    for(ll i=1;i<=n;i++)
        cin >> arr[i];
    
    for(ll i=0;i<m;i++){
        ll l, r;
        cin >> l >> r;
        queries.push_back(query(l-1,r,i));
    }

    for(ll i=1;i<=n;i++){
        arr[i] = (arr[i]^arr[i-1]);
    }

    sort(queries.begin(),queries.end());
    answ.assign(m,0);
    ll l = 0, r = -1, cnt=0;
    for(auto q:queries){
        while(q.l<l){
            l--;
            cnt += mp[arr[l]^k];
            mp[arr[l]]++;
        }
        while(r<q.r){
            r++;
            cnt += mp[arr[r]^k];
            mp[arr[r]]++;
        }
        while(l<q.l){
            mp[arr[l]]--;
            cnt -= mp[arr[l]^k];
            l++;
        }
        while(q.r<r){
            mp[arr[r]]--;
            cnt -= mp[arr[r]^k];
            r--;
        }
        answ[q.id] = cnt;
    }   

    for(ll i=0;i<m;i++)
        cout << answ[i] << "\n";

    return 0;
}