#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, x;
    ll answ, k;
    set<ll> s;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x;
        s.insert(x);
    }
    answ = x; k=-1;

    for(auto x:s){
        for(ll i=0, pot = 1L;i<31;i++,pot*=2L){
            if(s.count(x+pot)==1){
                if(s.count(x+pot+pot)==1){
                    cout << 3 <<'\n';
                    cout << x << ' ' << x+pot << ' ' << x+pot+pot << '\n';
                    return 0;
                }
                answ = x;
                k = pot;
            }
        }
    }

    if(k==-1){
        cout << 1 <<'\n';
        cout << answ << '\n';
    }
    else{
        cout << 2 <<'\n';
        cout << answ << ' ' << answ+k <<'\n';
    }

    return 0;
}