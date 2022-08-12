#include<bits/stdc++.h>
#define maxn int(305)
#define ll long long
using namespace std;

struct lanterna{
    int p, l, r;
    ll c;
};

const ll inf = 1e17;
int n, k;
vector<lanterna> arr, lanternas[maxn];
vector<int> ht;
ll dp[maxn][2][maxn][maxn];

ll solve(int i, bool dir, int l, int r){
    if(ht[i]<l || ht[i]>r)
        return inf;
    if(l==1 && r==n)
        return 0;
    if(dp[i][dir][l][r]!=-1)
        return dp[i][dir][l][r];
    dp[i][dir][l][r] = inf;
    int inc = (dir) ? 1 : -1;
    if(i+inc<=n && i+inc>=-1)
        dp[i][dir][l][r] = min(dp[i][dir][l][r],solve(i+inc,dir,l,r));
    for(auto x:lanternas[i]){
        int nl = l, nr = r;
        if(l<=x.l && x.l<=r){
            nr = max(r,x.r);
            nl = min(l,x.l);
        }
        if(x.l<=l && l<=x.r){
            nr = max(r,x.r);
            nl = min(l,x.l);
        }
        if(nl==l && nr==r) continue;
        dp[i][dir][l][r] = min({dp[i][dir][l][r], solve(i,0,nl,nr)+x.c, solve(i,1,nl,nr)+x.c});
    }

    return dp[i][dir][l][r];
}

int main(){
    cin >> n >> k;

    ht.assign(n+1,0);
    for(int i=1;i<=n;i++){
        cin >> ht[i];
    }

    for(int i=0;i<k;i++){
        lanterna nova;
        cin >> nova.p >> nova.c >> nova.l >> nova.r;
        lanternas[nova.p].push_back(nova);
        arr.push_back(nova);
    }
    
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<k;i++){
        ll answ = min(solve(arr[i].p, 0,arr[i].l,arr[i].r),solve(arr[i].p, 1,arr[i].l,arr[i].r));
        if(answ==inf) answ = -1;
        else answ += arr[i].c;
        cout << answ <<"\n";
    }

    return 0;
}