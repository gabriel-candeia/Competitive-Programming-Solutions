#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    ll n, l, w, a, b, answ=0;

    cin >> n;
    vector<pair<ll,ll>> p;
    multiset<ll> s;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        if(a>b)
            swap(a,b);
        p.push_back({a,b});
        s.insert(b);
        answ = max(answ,a*b);
    }

    sort(p.begin(),p.end());
    for(auto par:p){
        s.erase(s.find(par.second));
        auto last = s.end();
        if(s.begin()!=s.end()){
            last--;
            answ = max(answ,2ll*par.first*min((*last),par.second));
        }
    }

    printf("%.1lf\n",(long double)answ/2.0);

    return 0;
}