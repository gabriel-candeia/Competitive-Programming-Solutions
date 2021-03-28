#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define maxn 405
using namespace std;

const ll inf = 1e16;
ll dp[maxn][maxn], mat[maxn][maxn];

int main(){
    fastio();
    
    ll n, r, x, y, w;
    map<int,vector<int>> mp;
    vector<vector<int>> arr;
    vector<array<int,4>> queries[2];
    vector<int> answ;

    cin >> n >> r;

    for(int i=1;i<=n;i++){
        cin >> x;
        mp[x].push_back(i);
    }
    for(auto p:mp) 
        arr.push_back(p.second);

    for(int i=0;i<maxn;i++)
        for(int j=0;j<maxn;j++)
            mat[i][j] = inf;

    for(int i=0;i<r;i++){
        cin >> x >> y >> w;
        mat[x][y] = mat[y][x] = min(mat[x][y],w);
    }

    int q, a, b, k, t;
    cin >> q;
    for(int i=0;i<q;i++){
        cin >> a >> b >> k >> t;
        queries[t].push_back({k-1,a,b,i});
    }

    
    answ.assign(q,-1);
    for(int t=0;t<2;t++){
        sort(queries[t].begin(),queries[t].end());
        for(int i=0;i<maxn;i++)
            for(int j=0;j<maxn;j++)
                dp[i][j] = mat[i][j];

        for(int k=0,ptr=0;k<maxn;k++){
            if(arr.size()>k)
                for(auto x:arr[k])
                    for(int i=0;i<maxn;i++)
                        for(int j=0;j<maxn;j++)
                            dp[i][j] = min(dp[i][j],dp[i][x]+dp[j][x]);
            for(;ptr<queries[t].size() && k==queries[t][ptr][0];ptr++)
                answ[queries[t][ptr][3]] = (dp[queries[t][ptr][1]][queries[t][ptr][2]]==inf ? -1 : dp[queries[t][ptr][1]][queries[t][ptr][2]]);
        }

        reverse(arr.begin(),arr.end());
    }

    for(int i=0;i<q;i++)
        cout << answ[i] << '\n';

    return 0;
}

