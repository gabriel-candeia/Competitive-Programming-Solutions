#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll reverse(ll x){
    if(x%10==0) return false;
    ll acm = 0;
    while(x){
        acm = 10*acm + x%10;
        x/=10;
    }
    return acm;
}

int main(){
    ll a, b;
    set<ll> st;

    cin >> a >> b;

    for(ll i=1;i<=1e6;i++)
        st.insert(i*i);

    int answ = 0;
    for(auto x:st){
        if(x>=a && x<=b){
            answ += (st.find(reverse(x))!=st.end());
        }
    }

    cout << answ <<"\n";

    return 0;
}