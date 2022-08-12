#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
#define maxn int(1e5+5)
#define ll long long
using namespace std;

int n;
vector<ll> v, c;
ll best[maxn];
const ll inf = 1e17;

ll solve(ll a, ll b){
    for(int i=0;i<maxn;i++)
        best[i] = -inf;
    pair<int,int> gtr = {0,0};
    for(int i=0;i<n;i++){
        ll changeColor = 0, keepColor = best[c[i]];
        int selected = ((gtr.first!=c[i]) ? gtr.first : gtr.second);
        changeColor = max(changeColor,best[selected]);
        if(keepColor!=-inf)
            best[c[i]] = max({best[c[i]],changeColor+b*v[i],keepColor+a*v[i]});
        else
            best[c[i]] = max(best[c[i]],changeColor+b*v[i]);
        if(best[c[i]]>best[gtr.first]) gtr = {c[i],((gtr.first!=c[i]) ? gtr.first : gtr.second)};
        else if(best[c[i]]>best[gtr.second] && c[i]!=gtr.first) gtr = {gtr.first,c[i]};

    }
    return max(0ll,best[gtr.first]);
}

int main(){
    fastio();
    int q;

    cin >> n >> q;
    v.assign(n,0), c.assign(n,0);
    for(auto &x:v)
        cin >> x;
    for(auto &x:c)
        cin >> x;

    for(int i=0;i<q;i++){
        ll a, b;
        cin >> a >> b;
        cout << solve(a,b) <<"\n";
    }

    return 0;
}