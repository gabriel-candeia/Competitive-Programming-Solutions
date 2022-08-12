#include<bits/stdc++.h>
#define ll long long
#define maxn int(1e5+5)
#define maxm int(1e6+5)
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int n, q, dp[maxm];
vector<int> arr, adj[maxn], items;
ll answ = 0;
bool poss = true;

ll solve(int u, int p){
    ll mx = arr[u];
   for(auto v:adj[u]){
       if(v!=p){
           mx = max(mx,solve(v,u));
       }
   }
    
   if(mx-arr[u]>=0 && mx-arr[u] < maxm && dp[mx-arr[u]]!=-1){
        arr[u] += dp[mx-arr[u]];    
        answ += arr[u];
   }
   else{
        poss = false;
   }

   return arr[u];
}

int main(){
    fastio();
    cin >> n >> q;
    arr.assign(n+1,0);
    for(int i=1;i<=n;i++)
        cin >> arr[i];
    
    for(int i=1;i<=n-1;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    items.assign(q,0);
    for(auto &x:items){
        cin >> x;
    }
    
    dp[0] = 1;
    for(int i=0;i<q;i++)
        for(int j=maxm-1;j>=items[i];j--)
            dp[j] = dp[j]||dp[j-items[i]];

    int last = -1;
    for(int j=maxm-2;j>=0;j--){
        if(dp[j]){
            last = j;
        }
        dp[j] = last;
    }
    
    solve(1,-1);

    if(poss){
        cout << answ << "\n";
    }
    else{
        cout << -1 <<"\n";
    }

    return 0;
}