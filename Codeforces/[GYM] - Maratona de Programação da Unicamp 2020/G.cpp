#include<bits/stdc++.h>
#define ll long long
#define maxn int(2e3+100)
using namespace std;


ll dp[maxn][5], n, m;
ll notas[maxn], pontos[maxn], a[maxn], b[maxn], pa[maxn], pb[maxn];

ll solve(){
    for(ll i=0;i<=n+m;i++)
        for(ll j=0;j<5;j++)
            dp[i][j] = -(1<<30);
    dp[0][0] = 0;
    for(ll i=0;i<n+m;i++){
        for(ll j=0;j<5;j++){
            dp[i+1][min(j+pontos[i],4ll)] = max(dp[i+1][min(j+pontos[i],4ll)],dp[i][j]+notas[i]);            
            ll answ = 0;
            for(int k=i;k<i+j*10;k++)
                answ += notas[k];
            dp[min(i+j*10,n+m)][0] = max(dp[min(i+j*10,n+m)][0],2*answ+dp[i][j]);
        }
    }
    return max({dp[n+m][0],dp[n+m][1],dp[n+m][2],dp[n+m][3],dp[n+m][4]});
}


int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> a[i] >> pa[i];
    for(int i=0;i<m;i++)
        cin >> b[i] >> pb[i];

    ll answ=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<i;j++){
            notas[j] = a[j];
            pontos[j] = pa[j];
        }
        for(int j=i;j<i+m;j++){
            notas[j] = b[j-i];
            pontos[j] = pb[j-i];
        }
        for(int j=i+m;j<n+m;j++){
            notas[j] = a[j-m];
            pontos[j] = pa[j-m];
        }
        answ = max(answ,solve());
    }
    
    cout << answ*50ll <<'\n';

    return 0;   
}