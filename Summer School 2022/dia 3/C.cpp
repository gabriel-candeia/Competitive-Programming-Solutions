#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n, p, q;
vector<ll> arr;
vector<vector<int>> dp;

int solve(ll w){
    for(int j=0;j<=p;j++){
        int last=1, curr=1;
        for(int i=1;i<=n;i++){
            while(j && (arr[i]-arr[last]+1)>w) last++;
            while((arr[i]-arr[curr]+1)>2*w) curr++;
            if(j)
                dp[i][j] = min(dp[last-1][j-1],dp[curr-1][j]+1);
            else
                dp[i][j] = dp[curr-1][j]+1;
        }
    }

    /*for(int i=0;i<=n;i++){
        for(int j=0;j<=p;j++){
            cout << dp[i][j] <<" ";
        }
        cout<<"\n";
    }*/

    return dp[n][p];
}

ll bb(){
    ll l = 1, r = arr.back()-arr[0]+1, med, answ;
    while(l<=r){
        med = l + (r-l)/2;
        if(solve(med)<=q){
            answ = med;
            r = med-1;
        }
        else{
            l = med+1;
        }
    }
    return answ;
}


int main(){
    cin >> n >> p >> q;
    arr.assign(n+1,0);
    for(int i=1;i<=n;i++)
        cin >> arr[i];
    sort(arr.begin(),arr.end());
    arr[0] = arr[1];

    dp.assign(n+1,vector<int>(p+1,0));
    //cout << solve(1) << "\n";
    if(n<=p+q)
        cout << 1 << " ";
    else
        cout << bb() <<"\n";

    return 0;
}