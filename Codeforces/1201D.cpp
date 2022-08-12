#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll inf = 1e16;
set<ll> st;
ll custo(ll a, ll b){
    if(a>b) swap(a,b);
    ll mx = inf;
    auto it = st.lower_bound(a);
    if(it!=st.end())
        mx = min(mx,abs((*it)-a)+abs(b-(*it)));
    if(it!=st.begin()){
        it--;
        mx = min(mx,abs((*it)-a)+abs(b-(*it)));
    }
    it = st.lower_bound(b);
    if(it!=st.end())
        mx = min(mx,abs((*it)-a)+abs(b-(*it)));
    if(it!=st.begin()){
        it--;
        mx = min(mx,abs((*it)-a)+abs(b-(*it)));
    }
    return mx;
}


int main(){
    ll n, m, k, q;
    map<ll,ll> mx, mn;

    cin >> n >> m >> k >> q;
    for(int i=0;i<k;i++){
        ll a, b;
        cin >> a >> b;
        if(mx.find(a)==mx.end()){
            mx[a] = b;
            mn[a] = b;
        }
        else{
            mx[a] = max(mx[a],b);
            mn[a] = min(mn[a],b);
        }
    }
    
    for(int i=0;i<q;i++){
        int a;
        cin >> a;
        st.insert(a);
    }

    bool existe = true;
    if(mx.find(1)==mx.end()){
        existe = false;
        mx[1] = 1;
        mn[1] = 1;
    }

    ll answ = 0;
    int last = 1;
    vector<array<ll,2>> rngs;
    for(auto p:mx){
        answ += p.first-last;
        rngs.push_back({mn[p.first],p.second});
        last = p.first;
    }

    vector<vector<ll>> dp(n,vector<ll>(2,inf));
    dp[0][0] = 2*(rngs[0][1]-rngs[0][0]) + (rngs[0][0]-1);
    dp[0][1] = rngs[0][1]-rngs[0][0] + (rngs[0][0]-1);
    for(int i=1;i<rngs.size();i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                dp[i][j] = min(dp[i][j],dp[i-1][k] + custo(rngs[i][j],rngs[i-1][k]));
            }
        }
        ll a = min((dp[i][1] + rngs[i][1]-rngs[i][0]), (dp[i][0] + 2*(rngs[i][1]-rngs[i][0])));
        ll b = min((dp[i][0] + rngs[i][1]-rngs[i][0]), (dp[i][1] + 2*(rngs[i][1]-rngs[i][0])));
        dp[i][0] = a;
        dp[i][1] = b;
    }

    cout << answ+min(dp[rngs.size()-1][0],dp[rngs.size()-1][1]) <<"\n";

    return 0;
}