#include<bits/stdc++.h>
#define maxn 105
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL);
using namespace std;

int dp[maxn][maxn][maxn], parent[maxn][maxn][maxn];
vector<int> arr, freq, inc;

bool solve(int n, int k){
    for(int i=0;i<maxn;i++) 
        for(int j=0;j<maxn;j++) 
            dp[i][j][0] = 1;
    
    for(int i=1;i<=n;i++){
        for(int j=0;j<maxn;j++){
            for(int k=1;k<maxn;k++){
                for(int lim=0;lim<=j;lim++){
                    if((k-lim*freq[i])>=0 && dp[i-1][lim][k-lim*freq[i]]==1){
                        dp[i][j][k] = 1, parent[i][j][k] = lim;
                    }
                }
            }
        }
    }
    
    return dp[n][maxn-1][k];
}

int main(){
    fastio();
    int n, k;
    map<int,int> mp;

    cin >> n >> k;
    arr.assign(n,0);
    freq.assign(n+1,0);
    inc.assign(n+1,0);
    for(auto &x:arr)
        cin >> x, mp[x];

    int cnt = 0;
    for(auto &p:mp)
        p.second = ++cnt;

    for(auto x:arr)
        freq[mp[x]]++;
    
    for(int i=0;i<n;i++)
        k -= (i+1)*freq[i+1];
    
    if(k<0){
        cout << "nao\n";
        return 0;
    }

    
    bool poss = solve(cnt,k);
    
    if(poss){
        cout << "sim\n";
        for(int i=cnt,j=maxn-1,l=k;i;i--){
            inc[i] = parent[i][j][k];
            int nj, nk;
            nj = parent[i][j][k];
            nk = k - parent[i][j][k]*freq[i];
            j = nj;
            k = nk;
        }
        for(auto x:arr){
            cout << mp[x] + inc[mp[x]] << " ";
        }cout<<'\n';
    }
    else{
        cout << "nao\n";
    }
    

    return 0;
}