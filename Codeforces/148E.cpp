#include<bits/stdc++.h>
#define N 105
#define M 100005
#define ll long long
using namespace std;

ll dp[N][M];

ll max(ll a, ll b){
    return (a<b) ? b : a;
}

ll comp_best(vector<ll>& arr, int taken){
    ll sum=0, answ, n = arr.size();
    for(int i=0;i<taken;i++){
        sum+=arr[i];
    }
    answ = sum;
    for(int i=n-1;i>=n-taken;i--){
        sum+=arr[i]-arr[taken-n+i];
        answ = max(answ,sum);
    }

    return answ;
}

int main(){
    int n, m, tam;
    vector<vector<ll>> arr, best;

    cin >> n >> m;
    arr.assign(n,vector<ll>());
    best.assign(n,vector<ll>());
    for(int i=0;i<n;i++){
        cin >> tam;
        arr[i].assign(tam,0);
        best[i].assign(tam+1,0);
        for(int j=0;j<tam;j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=1;j<=arr[i].size();j++){
            best[i][j] = comp_best(arr[i],j);
            //cout << best[i][j] << ' ';
        }
        //cout << '\n';
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j] = 0;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<=m;j++){
            for(int k=0;k<=arr[i].size();k++){
                if(j+k<=m){
                    dp[i+1][j+k] = max(dp[i+1][j+k],dp[i][j]+best[i][k]);
                }
            }
        }
    }


    cout << dp[n][m] << '\n';

    return 0;
}
