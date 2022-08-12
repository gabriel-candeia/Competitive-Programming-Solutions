#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n, p, x, y, z, fst;
const ll mod = 998244353;



ll acm = 0;
struct pt{
    ll pos, val, pref;

    pt(ll x, ll i){
        val = x, pos = i, pref = 0;
    }
};

deque<pt> minq;

void add(ll val, ll pos){
    pt novo = pt(val,pos);

    while(minq.size() && minq.back().val>novo.val){
        minq.pop_back();
    }
    
    novo.pref = (novo.val*(novo.pos - (minq.back().pos+1)+1))%mod;
    novo.pref = (novo.pref + minq.back().pref)%mod;
    minq.push_back(novo);
    acm = (acm + minq.back().pref)%mod;

    /*for(auto item:minq){
        cout << item.val << " ";
    }
    cout<<"\n";*/
}

int main(){
    cin >> n >> p >> x >> y >> z >> fst;

    minq.push_back(pt(-1,0));
    ll xoracm = 0;
    for(int i=1;i<=n;i++){
        ll val = ((i==1) ? fst : (x*acm + y*minq.back().val + z)%p);
        add(val,i);
        //cout << val << " " << acm<< "\n";
        xoracm = xoracm^acm;
    }

    cout << xoracm <<"\n";


    return 0;
}