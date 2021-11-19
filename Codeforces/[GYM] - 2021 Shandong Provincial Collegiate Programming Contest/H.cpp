#include<bits/stdc++.h>
#define maxn 305
#define ll long long
using namespace std;

ll dp[maxn][maxn];

int main(){
    int n, h, s;
    vector<array<ll,3>> arr;

    cin >> n >> h >> s;
    
    for(int i=0;i<n;i++){
        int a, b, c;
        cin >> a >> b >> c;
        arr.push_back({c,a,b});
    }

    for(int i=0;i<n;i++){
        for(int j=h;j>=0;j--){
            for(int k=s;k>=0;k--){
                int j1 = j-arr[i][1], k1 = k-arr[i][2];
                if(k1<0)
                    j1+=k1, k1 = 0;
                if(j1<=0)
                    continue;
                dp[j][k] = max(dp[j][k],dp[j1][k1]+arr[i][0]);
            }
        }
    }

    cout << dp[h][s] << "\n";

    return 0;
}