#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL);
using namespace std;

int main(){
    int n, t;
    vector<array<int,3>> arr;
    vector<int> dp;

    cin >> n >> t;
    for(int i=0;i<n;i++){
        int qtd, h, d;
        cin >> h >> d >> qtd;
        for(int j=0;j<qtd;j++){
            int a;
            cin >> a;
            arr.push_back(array<int,3>{a+d,a,h});
        }
    }

    n = arr.size();
    dp.assign(n,0);
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++){
        dp[i] = arr[i][2];
        for(int j=0;j<i;j++){
            if(arr[j][0] <= arr[i][1]){
                dp[i] = max(dp[i],dp[j]+arr[i][2]);
            }
        }
    }

    int answ = 0;
    for(int i=0;i<dp.size();i++)
        answ = max(answ,dp[i]);

    cout << answ << "\n";

    return 0;
}


