#include<bits/stdc++.h>
#define ll long long
#define N 201
using namespace std;

ll dp[N][N][N];

int main(){
    int l[3], ptr[3];
    vector<ll> nums[3];

    cin >> l[0] >> l[1] >> l[2];
    ptr[0] = ptr[1] = ptr[2] = 0;
    for(int i=0;i<3;i++){
        nums[i].assign(l[i],0);
        for(int j=0;j<l[i];j++){
            cin >> nums[i][j];
        }
        sort(nums[i].rbegin(),nums[i].rend());
    }

    ll answ=0, last=-1;
    for(int i=0;i<=l[0];i++){
        for(int j=0;j<=l[1];j++){
            for(int k=0;k<=l[2];k++){
                if(i<l[0] && j<l[1])
                    dp[i+1][j+1][k] = max(dp[i+1][j+1][k],dp[i][j][k]+nums[0][i]*nums[1][j]);
                if(i<l[0] && k<l[2])
                    dp[i+1][j][k+1] = max(dp[i+1][j][k+1],dp[i][j][k]+nums[0][i]*nums[2][k]);
                if(j<l[1] && k<l[2])
                    dp[i][j+1][k+1] = max(dp[i][j+1][k+1],dp[i][j][k]+nums[1][j]*nums[2][k]);        
            }
        }
    }

    for(int i=0;i<=l[0];i++){
        for(int j=0;j<=l[1];j++){
            for(int k=0;k<=l[2];k++){
                answ = max(dp[i][j][k],answ);
            }
        }
    }

    cout << answ <<'\n';


    return 0;
}