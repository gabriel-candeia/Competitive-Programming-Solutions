#include<bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
using namespace std;

void att(pair<ll,ll> p1,pair<ll,ll> p2,ll& a,ll& b,ll& c){
    a = p1.ff-p2.ff;
    b = -(p1.ss-p2.ss);
    c = p2.ss*p1.ff - p2.ff*p1.ss;
}

bool ta_na_reta(pair<ll,ll> p, ll a,ll b,ll c){
    return (a*p.ss+b*p.ff == c);
}

bool forma_reta(vector<pair<ll,ll>> rem){
    if(rem.size()<=2){
        return true;
    }
    ll a, b, c;
    att(rem[0],rem[1],a,b,c);
    for(int i=2;i<rem.size();i++){
        if(!ta_na_reta(rem[i],a,b,c)){
            return false;
        }
    }
    return true;
}

int main(){
    ll n, x, y, a, b, c;
    bool poss = false;
    vector<pair<ll,ll>> arr, rem;

    cin >> n;
    for(ll i=0;i<n;i++){
        cin >> x >> y;
        arr.push_back({x,y});
    }

    if(n<=3){
        poss = true;
    }
    else{
        for(int i=0;i<2;i++){
            for(int j=i+1;j<=2;j++){
                att(arr[i],arr[j],a,b,c); rem.clear();
                for(int k=0;k<n;k++){
                    if(!ta_na_reta(arr[k],a,b,c)){
                        rem.push_back(arr[k]);
                    }
                }
                poss = (poss || forma_reta(rem));
                //cout << poss <<" "<< i << " " << j <<'\n';
                //cout << ta_na_reta(arr[i],a,b,c) << '\n';
                //cout << a << " " << b << " " << c <<'\n';
            }
        }

    }

    cout << ((poss) ? "YES" : "NO" )<< '\n';

    return 0;
}