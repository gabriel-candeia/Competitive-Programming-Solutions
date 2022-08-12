#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

const ll inf =  1e17;

struct line{
    ll m, k;

    ll eval(ll x){
        return m*x+k;
    }

    ld tempo(const line& o){
        return (k-o.k)*1.0/(o.m-m);
    }
};

int main(){
    int n;
    vector<ll> a, b;

    cin >> n;
    a.assign(n,0);
    b.assign(n,0);
    for(auto &x:a)
        cin >> x;
    for(auto &x:b)
        cin >> x;

    vector<ll> dp(n,inf);
    deque<line> st;
    dp[0] = 0;
    st.push_back({b[0],dp[0]});

    for(int i=1;i<n;i++){
        while(st.size()>=2 && st[0].eval(a[i])>st[1].eval(a[i])) 
            st.pop_front();
        dp[i] = st[0].eval(a[i]);
        line novo = {b[i],dp[i]};
        while(st.size()>=2 && st[st.size()-2].tempo(st[st.size()-1])>=st[st.size()-2].tempo(novo))
            st.pop_back();
        st.push_back(novo);
    }
    
    cout << dp[n-1] <<"\n";

    return 0;
}