#include<bits/stdc++.h>
#define ll long long 
using namespace std;

class FenwickTree{
    private:
        vector<ll> ft;
        int n;      
    public:
        FenwickTree(int siz){
            n = siz+1;
            ft.assign(n,0);
        }

        ll lsOne(ll x){
            return (x&(-x));
        }

        ll query(ll r){
            ll sum = 0;
            for(;r;r-=lsOne(r)){
                sum += ft[r];
            }
            return sum;
        }

        void update(ll i, ll v){
            for(;i<n;i+=lsOne(i)){
                ft[i]+=v;
            }
        }
};

int main(){
    ll n, x, mn=0;
    vector<ll> h;

    cin >> n >> x;
    h.assign(n+1,0);
    for(int i=1;i<=n;i++){
        cin >> h[i];
        h[i] = ((h[i]>=x) ? 1 : -1);
        h[i]+=h[i-1];
        mn = min(mn,h[i]);
    }

    FenwickTree ft(n+1);
    ll answ=0;
    for(int i=0;i<=n;i++){
        h[i]+=-mn+1;
        //cout << h[i] << '\n';
        answ += ft.query(h[i]);
        ft.update(h[i],1);
    }

    cout << answ << '\n';

    return 0;
}