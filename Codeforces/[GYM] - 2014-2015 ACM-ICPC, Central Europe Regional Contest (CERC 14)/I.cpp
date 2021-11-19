#include<bits/stdc++.h>
#define ll long long
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL);
using namespace std;

int main(){
    ll t;
    fastio();
    cin >> t;
    while(t--){
        ll n, x=0, y=0;
        vector<pair<ll,ll>> arr;

        cin >> n;
        for(ll i=0;i<n;i++){
            int a, b; string s;
            cin >> b >> s;
            a = (s=="B" ? 0 : 1);
            if(a==0) x += b;
            else y += b;
            if(!arr.size() || a != arr.back().first)
                arr.push_back({a,b});
            else
                arr.back().second+=b;
        }
        
        if(x==0 || y==0)
            cout << max(x,y) << "\n";
        else{
            ll d = __gcd(x,y), acm[2] = {0,0}, total[2] = {x/d, y/d}, answ = 0;
            for(auto p:arr){
                if(acm[1-p.first]%total[1-p.first]==0){
                    ll q = acm[1-p.first]/total[1-p.first];
                    if(acm[p.first]+p.second>=q*total[p.first] && acm[p.first]<q*total[p.first])
                        answ++;
                }
                acm[p.first] += p.second;
            }
            cout << answ << "\n";
        }
    }

    return 0;
}