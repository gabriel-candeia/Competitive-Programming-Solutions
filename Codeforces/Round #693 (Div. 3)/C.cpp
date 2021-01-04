#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        int n, x, y;
        vector<ll> dp, arr;
        cin >> n;

        arr.assign(n,0); dp.assign(n,0);
        for(int i=0;i<n;i++)
            cin >> arr[i];

        for(int i=n-1;i>=0;i--){
            dp[i] = arr[i];
            if(i+arr[i]<n)
                dp[i] = dp[i+arr[i]]+arr[i];
        }

        ll answ = 0;
        for(int i=0;i<n;i++){
            answ = max(answ,dp[i]);
        }
        cout<< answ << '\n';
    }

    return 0;
}