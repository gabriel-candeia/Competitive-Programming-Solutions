#include<bits/stdc++.h>
#define maxn int(2e5+5)
#define ll long long
using namespace std;

ll n, m, k, t;
vector<ll> arr;
vector<array<ll,3>> traps;

bool isok(int x){
    ll answ = n+1, mx=0, mn=n+1; x--;
    vector<int> cnt(maxn,0);

    for(auto p:traps){
        if(arr[x]<p[2]){
            cnt[p[0]]++;
            cnt[p[1]+1]--;
        }
    }
    
    for(int i=1;i<=n;i++)
        cnt[i]+=cnt[i-1];

    for(int i=1;i<=n;i++)
        answ += 2*(cnt[i]!=0);

    return (answ<=t);
}

int main(){ 
    cin >> m >> n >> k >> t;

    arr.assign(m,0);
    for(int i=0;i<m;i++)
        cin >> arr[i];

    for(int i=0;i<k;i++){
        ll l, r, d;
        cin >> l >> r >> d;
        traps.push_back({l,r,d});
    }

    sort(arr.rbegin(),arr.rend());

    int l=1, r=m, med, answ=0;
    while(l<=r){
        med = l +(r-l)/2;
        if(isok(med)){
            answ = med;
            l = med+1;
        }
        else{
            r = med-1;
        }
    }

    cout << answ <<'\n';

    return 0;
}