#include<bits/stdc++.h>
#define ll long long
#define N int(int(2e5)+5)
using namespace std;

ll dp[N][10];

int main(){
    
    ll n, k,x,y;

    memset(dp,-1,sizeof(dp));
    dp[0][0] = 0;

    cin >> n;
    for(ll i=0;i<n;i++){
        cin >> k;
        vector<ll> cst[3];
        for(ll j=0;j<k;j++){
            cin >> x >> y;
            cst[x-1].push_back(y);
        }
        cst[0].push_back(0); cst[0].push_back(0); cst[0].push_back(0);
        cst[1].push_back(0);
        cst[2].push_back(0);
        for(ll j=0;j<3;j++){
            sort(cst[j].rbegin(),cst[j].rend());
        }
        for(ll j=0;j<10;j++){
            if(dp[i][j]!=-1){
                dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
                if(j+1<10){
                    dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j]+max({cst[0][0],cst[1][0],cst[2][0]}));
                }
                else{
                    dp[i+1][(j+1)%10] = max(dp[i+1][(j+1)%10],dp[i][j]+2*max({cst[0][0],cst[1][0],cst[2][0]}));
                }
                if(cst[0].size()>=5 || (cst[0].size()>=4 && cst[1].size()>=2)){
                    ll a = cst[0][0], b = max(cst[0][1],cst[1][0]);
                    if(j+2<10){
                        dp[i+1][j+2] = max(dp[i+1][j+2],dp[i][j]+a+b);
                    }
                    else{
                        dp[i+1][(j+2)%10] = max(dp[i+1][(j+2)%10],dp[i][j]+2*max(a,b)+min(a,b));
                    }
                }
                if(cst[0].size()>=6){
                    if(j+3<10){
                        dp[i+1][j+3] = max(dp[i+1][j+3],dp[i][j]+cst[0][0]+cst[0][1]+cst[0][2]);
                    }
                    else{
                        dp[i+1][(j+3)%10] = max(dp[i+1][(j+3)%10],dp[i][j]+2*(cst[0][0])+cst[0][1]+cst[0][2]);
                    }
                }
            }   
        }
    }

    ll answ=0;
    for(ll i=0;i<10;i++){
        answ = max(dp[n][i],answ);
    }

    /*for(ll i=0;i<=n;i++){
        for(ll j=0;j<10;j++){
            cout << dp[i][j] << ' ';
        }
        cout <<'\n';
    }*/
    
    cout << answ << '\n';

    return 0;
}