#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll inf = 1e17;
int main(){
    int n, k;
    vector<ll> dp, arr, close;

    cin >> n >> k;
    dp.assign(n+k+1,inf); 
    arr.assign(n+k+1,0);
    close.assign(n+k+1,0);

    char c;
    for(int i=1+k;i<=n+k;i++){
        cin >> c;
        if(c=='1'){
            arr[i-k] = 1;
            if(i+k+1 <= n+k) close[i+k+1] = -1;
        } 
    }

    dp[0] = 0;
    queue<ll> q;
    for(int i=1;i<=n+k;i++){
        if(close[i]==-1)
            q.pop();
        if(arr[i]==1)
            q.push(dp[i-1]+i);

        dp[i] = dp[i-1]+ max(i-k,0);
        if(q.size())
            dp[i] = min(dp[i],q.front());
        //cout << arr[i] << ' ';
    }//cout<<'\n';

    while(q.size()){
        dp[n+k] = min(dp[n+k],q.front()); 
        q.pop();
    }

    cout << dp[n+k] << '\n';

    return 0;
}