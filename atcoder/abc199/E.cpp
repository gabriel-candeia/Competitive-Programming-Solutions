#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool teste(int msk, int y, int z){
    int acm = 0;
    for(int i=1, j=msk;j;j/=2,i++){
        if(i<=y) acm += (j%2);
    }
    return (acm<=z);
}


int main(){
    int n, m;
    vector<vector<pair<int,int>>> arr;

    cin >> n >> m;
    arr.assign(n+1,vector<pair<int,int>>());
    for(int i=0;i<m;i++){
        int x, y, z;
        cin >> x >> y >> z;
        arr[x].push_back({y,z});
    }

    vector<ll> dp((1<<20),0);
    dp[0] = 1;
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(i&(1<<j)) continue;
            ll x = __builtin_popcount(i^(1<<j));
            bool isok = true;
            for(auto p:arr[x])
                isok = isok&&(teste(i^(1<<j),p.first,p.second)); 
            if(isok) dp[i^(1<<j)] += dp[i];
        }
    }

    cout << dp[(1<<n)-1] << "\n";
    return 0;
}