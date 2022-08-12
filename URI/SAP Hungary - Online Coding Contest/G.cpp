#include<bits/stdc++.h>
using namespace std;

int main(){ 
    int k;
    cin >> k;
    vector<int> arr(k,0);
    for(auto &x:arr)
        cin >> x;

    const int inf = 500;
    vector<vector<int>> dp((1<<k)+1,vector<int>(10,inf));

    for(int i=0;i<k;i++){
        dp[(1<<i)][arr[i]] = arr[i];
    }

    for(int msk=1;msk<(1<<k);msk++){
        for(int j=0;j<k;j++){
            if((msk&(1<<j))){
                int sub = msk^(1<<j);
                for(int d2=1,ptr=7,mn=inf;d2<=arr[j];d2++){
                    while(ptr>=arr[j]-d2+1)
                        mn = min(mn,dp[sub][ptr]), ptr--;
                    dp[msk][d2] = min(dp[msk][d2],mn+d2);
                }
            }
        }
    }
    
    int answ = inf;
    for(int i=0;i<10;i++){
        answ = min(answ,dp[(1<<k)-1][i]);
    }
    //cout << dp[7][0]  <<"\n";
    cout << answ <<"\n";

    return 0;
}