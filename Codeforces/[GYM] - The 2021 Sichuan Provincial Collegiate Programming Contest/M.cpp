#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, k, x, aux;
    vector<ll> t, p, s;

    cin >> n >> k >> x >> aux;
    
    t.push_back(0);
    p.push_back(aux);

    s.assign(n,0);
    for(auto &x:s){
        cin >> x;
    }

    for(int i=0;i<k;i++){
        ll temp;
        cin >> temp;
        t.push_back(temp);
    }

    for(int i=0;i<k;i++){
        ll temp;
        cin >> temp;
        p.push_back(temp);
    }

    sort(s.begin(),s.end());

    int answ = 0;
    for(int i=0;i<=k;i++){
        while(s.size() && s.back()*(p[i]-t[i])>=x){
            s.pop_back();
            answ++;
        }
    }

    cout << answ <<"\n";

    return 0;
}