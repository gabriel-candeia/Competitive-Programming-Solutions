#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n;
vector<ll> a;

ll f(ll l, ll r){
    if(r-l+1<=1)
        return max(r-l+1,0ll);
    ll mn = a[l];
    bool diff = false;
    for(ll i=l;i<=r;i++){
        mn = min(mn,a[i]);
    }
    for(ll i=l;i<=r;i++){
        if(a[i]!=mn) 
            diff = true;
    }
    if(!diff)
        return min(mn,r-l+1);
    ll answ = mn, last = l;
    for(ll i=l;i<=r;i++){
        a[i]-=mn;
    }

    for(ll i=l;i<=r;i++){
        if(a[i]==0){
            answ += f(last,i-1);
            last = i+1;
        }
    }
    answ += f(last,r);

    return min(answ,r-l+1);
}


int main(){
    cin >> n;
    a.assign(n,0);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    cout << f(0,n-1) << '\n';

    return 0;
}