#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct minqueue{
    int inserted, removed;
    deque<pair<ll,int>> dq;

    minqueue(){
        inserted = removed = 0;
    }

    void push(ll x){
        while(dq.size() && dq.back().first >= x)
            dq.pop_back();
        dq.push_back({x,inserted++});
    }

    void pop(){
        if(dq.size() && dq.front().second==removed)
            dq.pop_front();
        removed++;
    }

    void clear(){
        inserted = 0, removed = 0, dq.clear();
    }

    ll front(){
       return dq.front().first;
    }
};

const ll inf = 1e18;
vector<vector<ll>> dp, cost;
int n, m;
vector<pair<int,int>> rngs;

int main(){

    cin >> n >> m;
    dp.assign(m+1,vector<ll>(n+1,inf));
    cost.assign(m,vector<ll>(n+1,inf));

    for(int i=1;i<=n;i++)
        dp[m][i] = 0;

    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        rngs.push_back({a,b});
    }
    rngs.push_back({0,0});

    for(int i=0;i<m;i++){
        int d = rngs[i].second-rngs[i].first+1;
        for(int j=1;j+d-1<=n;j++){
            cost[i][j] = abs(rngs[i].first-j);
        }
    }
    
    minqueue q;
    for(int i=m-1;i>=0;i--){

        int d1 = rngs[i].second-rngs[i].first+1, d2 = rngs[i+1].second-rngs[i+1].first+1;
        int l=1, r=1;
        q.push(dp[i+1][1]);
        for(int j=1;j<=n;j++){
            while(l>1 && j-l+1<d2)
                q.push(dp[i+1][--l]);
            while(l<j && j-l+1>d2)
                l++, q.pop();
            while(r<n && r-j+1<d1)
                q.push(dp[i+1][++r]);
            dp[i][j] = min(inf,cost[i][j] + q.front());
        }
        q.clear();
    }

    ll answ = inf;
    for(int i=1;i<=n;i++)
        answ = min(answ,dp[0][i]);

    /*for(int i=0;i<m;i++){
        for(int j=1;j<=n;j++)
            cout << cost[i][j] << " ";
        cout<<"\n";
    }
    cout <<"\n";

    for(int i=0;i<m;i++){    
        for(int j=1;j<=n;j++)
            cout << ((dp[i][j]==inf) ? -1 : dp[i][j]) << " ";
        cout<<"\n";
    }*/

    cout << answ <<"\n";

    return 0;
}