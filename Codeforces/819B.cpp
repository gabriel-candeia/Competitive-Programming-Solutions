#include<bits/stdc++.h>
#define ll long long
#define maxn int(4e6+5)
using namespace std;

ll ft[maxn], arr[maxn], n;

ll lsone(ll x){
    return x&(-x);
}

void update(ll r, ll v){
    r+=n;
    if(r==0) return;
    for(;r<maxn;r+=lsone(r))
        ft[r]+=v;
}

ll query(ll r){
    r+=n;
    ll sum = 0;
    for(;r;r-=lsone(r))
        sum+=ft[r];
    return sum;
}

ll query(ll l, ll r){
    return query(r) - query(l-1);
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];

    ll answ = 1e17, acm = 0, sft=0;
    
    for(int i=0;i<n;i++){
        update(arr[i]-i-1,1);
        acm += abs(arr[i]-i-1);
    }

    answ = acm;
    for(int i=0;i<n-1;i++){
        acm -= abs(arr[n-1-i]-n);
        acm += abs(arr[n-1-i]-1);
        update(arr[n-1-i]-n+i,-1);
        acm += query(i);
        acm -= query(i+1,maxn-n-1);
        update(arr[n-1-i]+i,1);

        if(acm<answ){
            sft = i+1;
            answ = acm;
        }
    }

    cout << answ << " " << sft << '\n';

    return 0;
}