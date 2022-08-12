#include<bits/stdc++.h>
#define ll long long
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int n, q;
vector<int> arr;
vector<array<ll,3>> rngs;

ll cnt(ll pos){
    ll answ = 0;
    for(auto [l,r,x]:rngs)
        answ += max(0ll,min(r,pos)-l+1)*x;
    return answ;
}

ll bb(ll x){
    ll l = 0, r = arr.size()-1, answ = -1, med = -1;
    while(l<=r){
        med = l + (r-l)/2;
        if(cnt(med)<=x){
            answ = med;
            l = med+1;
        }
        else{
            r = med-1;
        }
    }
    return answ;
}

int main(){
    fastio();
    cin >> n >> q;

    arr.assign(n,0);
    for(auto &x:arr)
        cin >> x;

    for(int i=0;i<q;i++){
        int k;

        cin >> k;

        ll qtd = 0;
        for(int j=0;j<k;j++){
            ll a, b, c;
            cin >> a >> b >> c;
            rngs.push_back({a,b,c});
            qtd += c*(b-a+1);
        }

        ll answ = arr[bb((qtd-1)/2)] + arr[bb((qtd-1)/2+(qtd-1)%2)];

        cout << fixed << setprecision(14.0) << answ/2.0 <<"\n";

        rngs.clear();
    }


    return 0;
}