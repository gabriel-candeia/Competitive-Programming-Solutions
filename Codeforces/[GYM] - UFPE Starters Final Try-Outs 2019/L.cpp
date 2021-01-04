#include <bits/stdc++.h>
#define ll int
#define maxn int(1e4+5)
using namespace std;

ll dp[maxn][maxn], n, q;
vector<array<ll,3>> items; //tempo, valor, capacidade

void solve(){
    for(int j=items[0][2];j<maxn;j++)
        dp[0][j] = items[0][1];
        
    for(int i=1;i<n;i++){
        for(int j=maxn-1;j>=0;j--){
            dp[i][j] = dp[i-1][j];
            if(j>=items[i][2])
                dp[i][j] = max(dp[i][j],dp[i-1][j-items[i][2]]+items[i][1]);
        }
    }
}

int bb(int x){
    //primeira posição que o tempo>x
    int l = 0, r = n-1, med, answ = -1;
    while(l<=r){
        med = l+(r-l)/2;
        if(items[med][0]>x){
            answ = med;
            l = med+1;
        }
        else{
            r = med-1;
        }
    }
    return answ;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int v, w, t;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> v >> w >> t;        
        items.push_back({t,v,w});
    }    
    sort(items.rbegin(), items.rend());
    if(n)
        solve();
    for(int i = 0; i < q; i++){
        cin >> t >> w;
        t = bb(t);
        if(t==-1){
            cout << 0 <<'\n';
        }else{
            //cout << t << " " << w <<'\n';
            cout << dp[t][w] << '\n';
        }
    }
    return 0;
}
