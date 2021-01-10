#include<bits/stdc++.h>
#define maxn int(2e5+5)
using namespace std;

const int inf = 1e9;
int dp[maxn], arr[maxn], n;
vector<int> adj[maxn];

int main(){
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];

    memset(dp,-1,sizeof(dp));

    
    queue<int> q;
    for(int i=0;i<n;i++){
        if(i-arr[i]>=0 && arr[i-arr[i]]%2!=arr[i]%2 || i+arr[i]<n && arr[i+arr[i]]%2!=arr[i]%2){
            dp[i] = 1;
            q.push(i);
        }
        else{
            if(i-arr[i]>=0)
                adj[i-arr[i]].push_back(i);
            if(i+arr[i]<n)
                adj[i+arr[i]].push_back(i);
        }
    }

    int u;
    while(q.size()){
        u = q.front(); q.pop();

        for(auto v:adj[u]){
            if(dp[v]==-1){
                dp[v] = dp[u]+1;
                q.push(v);
            }
        }
    }

    for(int i=0;i<n;i++)
        cout << dp[i] << " ";
    cout<<'\n';
    
    return 0;
}