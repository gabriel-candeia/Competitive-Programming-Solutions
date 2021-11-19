#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int main(){
    fastio();
    int n, k;
    vector<int> arr, dp, nxt, succ, parent, parentRemoved;
    vector<vector<int>> adj;
    map<int,int> last;

    cin >> n >> k;
    arr.assign(n,0), dp.assign(n+1,n), nxt.assign(n+1,n), succ.assign(n+1,n), parent.assign(n+1,-1), parentRemoved.assign(n+1,-1);
    for(auto &x:arr) cin >> x;

    if(k==1){
        cout << n <<"\n";
        for(int i=1;i<=n;i++)
            cout << i << " ";
        cout<<'\n';
        return 0;
    }

    for(int i=n-1;i>=0;i--){
        if(last.find(arr[i])!=last.end())
            nxt[i] = last[arr[i]];
        if(last.find(arr[i]+1)!=last.end())
            succ[i] = last[arr[i]+1];
        last[arr[i]] = i;
    }

    adj.assign(k+1,vector<int>());
    for(int i=0;i<n;i++) if(arr[i]==1){dp[i]=0; break;}
    vector<int> freq(k+1,0); freq[0] = 1;
    for(int i=0;i<n;i++){ 
        if(freq[arr[i]-1]){
            adj[arr[i]].push_back(i);
            freq[arr[i]] = 1;
        }
    }
    
    
    
    bool ok = true;
    for(int i=1;i<=k;i++){
        ok = (ok && adj[i].size()!=0);
        for(auto x:adj[i]){
            if(dp[nxt[x]] > dp[x]+1){
                parent[nxt[x]] = x;
                parentRemoved[nxt[x]] = 1;
                dp[nxt[x]] = dp[x]+1;
            }
            if(i!=k && dp[succ[x]] > dp[x]){
                parent[succ[x]] = x;
                parentRemoved[succ[x]] = 0;
                dp[succ[x]] = dp[x];
            }
        }
    }

    if(!ok){
        cout << 0 << "\n";
    }
    else{
        int ult = 0;
        for(ult = n-1;ult>=0 && arr[ult]!=k;ult--);
        vector<int> answ;
        for(int i=n;parent[i]!=-1;i=parent[i])
            if(parentRemoved[i])
                answ.push_back(parent[i]+1);
        reverse(answ.begin(),answ.end());
        cout << answ.size() << "\n";
        for(auto x:answ)
            cout << x << " ";
        cout<<'\n';
    }
    return 0;
}