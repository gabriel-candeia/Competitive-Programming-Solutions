#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t, s, w, cnts, cntw, p, f;

    cin >> t;
    while(t--){
        cin >> p >> f >> cnts >> cntw >> s >> w;

        if(w<s){
            swap(w,s);
            swap(cntw,cnts);
        }

        ll total = 0;
        
        for(ll i=0;i<=cnts;i++){
            ll remp = max(p - i*s,0ll), remf = max(f - (cnts-i)*s,0ll);
            total = max(total,min(i,p/s) + min(cnts-i,f/s) + min(cntw,remp/w+remf/w));
        }
        cout << total <<'\n';
    }

    return 0;
}