#include<bits/stdc++.h>
#define ll long long
#define maxn 10
#define maxm int(1e5+5)
using namespace std;

const ll mod = 998244353;
ll dp[maxn][maxm];
vector<int> arr;
int n;


int main(){
    cin >> n;
    arr.assign(n,0);
    for(auto &x:arr)
        cin >> x;

    dp[(arr[0]+arr[1])%10][2]++;
    dp[(arr[0]*arr[1])%10][2]++;

    for(int i=2;i<n;i++){
        for(int j=0;j<10;j++){
            dp[(j+arr[i])%10][i+1] = (dp[(j+arr[i])%10][i+1] + dp[j][i])%mod;
            dp[(j*arr[i])%10][i+1] = (dp[(j*arr[i])%10][i+1] + dp[j][i])%mod;
        }
    }

    for(int i=0;i<10;i++){
        cout << dp[i][n] << "\n";
    }

    return 0;
}