#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, m;
    vector<ll> h, w, suff;  
    cin >> n >> m;

    h.assign(n,0);
    for(auto &x:h)
        cin >> x;

    w.assign(m,0);
    for(auto &x:w)
        cin >> x;

    sort(h.begin(),h.end());
    sort(w.begin(),w.end());

    suff.assign(n+2,0);
    for(ll i=n-2;i>=0;i--)
        suff[i] = suff[i+2] + abs(h[i]-h[i+1]);

    ll ptr = 0, acm = 0, answ = 1ll<<60, temp = 0;
    for(int i=0;i<m;i++){
        while(ptr<n && h[ptr]<=w[i]){
            if(ptr%2)
                acm+=abs(h[ptr]-h[ptr-1]);
            ptr++;
        }
        if(ptr==n)
            temp = acm + abs(w[i]-h[n-1]);
        else if(ptr%2)
            temp = acm + abs(w[i]-h[ptr-1]) + suff[ptr];
        else
            temp = acm + abs(w[i]-h[ptr]) + suff[ptr+1];

        answ = min(answ,temp);
    }
    
    cout << answ <<'\n';
    return 0;
}