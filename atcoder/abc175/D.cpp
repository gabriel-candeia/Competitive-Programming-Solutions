#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, k;
    vector<ll> p, c;

    cin >> n >> k;
    p.assign(n+1,0);
    c.assign(n+1,0);
    for(int i=1;i<=n;i++){
        cin >> p[i];
    }
    for(int i=1;i<=n;i++){
        cin >> c[i];
    }

    vector<ll> best(n+1,0);
    for(int i=1;i<=n;i++){
        best[i] = c[p[i]];
    }
    for(int i=1;i<=n;i++){
        vector<ll> d(n+1,0), visited(n+1,0);
        ll cnt = 0, j=i;
        ll answ=0, last=i;
        while(cnt<k && visited[j]==false){
            visited[j] = ++cnt;
            d[j] = answ;
            last = j;
            j = p[j];
            answ+=c[j];
            best[i] = max(best[i],answ);
        }
        
        ll k1 = max(k-cnt,0ll), cycle = visited[last]-visited[j]+1, qtd;
        qtd = max(k1/cycle-1,0ll);
        answ += 1ll*(answ-d[j])*1ll*(qtd);
        best[i] = max(best[i],answ);
        k1 = k1%cycle + (qtd>0)*cycle;
        while(k1--){
            j = p[j];
            answ+=c[j];
            best[i] = max(best[i],answ);
        }
    }

    ll resp=best[1];
    for(int i=1;i<=n;i++){
        resp = max(resp,best[i]);
    }
    
    cout << resp <<"\n";

    return 0;
}

