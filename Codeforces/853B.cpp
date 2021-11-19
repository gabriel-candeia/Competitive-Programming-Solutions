#include<bits/stdc++.h>
#define maxn int(1e6+5)
#define ll long long
using namespace std;

const ll inf = 1e17;
vector<array<ll,2>> arr[2][maxn];
vector<ll> mn[2];

int main(){
    int n, m, k;
    
    cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        if(b!=0) arr[0][a].push_back({b,d});
        else arr[1][a].push_back({c,d});
    }
    
    for(int i=0;i<2;i++)
        mn[i].assign(maxn,inf);
    vector<ll> best(n+2,inf);
    
    ll acm = 0;
    for(int i=1, cc=0;i<maxn;i++){
        for(auto p:arr[0][i]){
            if(best[p[0]]==inf && p[1]!=inf) cc++;
            if(best[p[0]]!=inf) acm -= best[p[0]];
            best[p[0]] = min(best[p[0]],p[1]);
            if(best[p[0]]!=inf) acm += best[p[0]];
        }
        mn[0][i] = mn[0][i-1];
        if(cc==n)
            mn[0][i] = min(acm,mn[0][i]);
    }
    acm = 0;
    best.assign(n+2,inf);
    for(int i=maxn-2, cc=0;i;i--){
        for(auto p:arr[1][i]){
            if(best[p[0]]==inf && p[1]!=inf) cc++;
            if(best[p[0]]!=inf) acm -= best[p[0]];
            best[p[0]] = min(best[p[0]],p[1]);
            if(best[p[0]]!=inf) acm += best[p[0]];
        }
        mn[1][i] = mn[1][i+1];
        if(cc==n)
            mn[1][i] = min(acm,mn[1][i]);
    }
    
    ll answ = inf;
    for(int i=1;i+k+1<maxn;i++){
        if(mn[0][i]+mn[1][i+k+1]<answ){
            answ = min(answ,mn[0][i]+mn[1][i+k+1]);
            //cout << i << " " << answ <<"\n";
        }
    }
    if(answ==inf)
        answ = -1;
    cout << answ <<'\n';

    return 0;
}