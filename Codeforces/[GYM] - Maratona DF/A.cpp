#include<bits/stdc++.h>
#define maxn 21
#define maxm int((1<<20)+1)
using namespace std;

float dp[maxn][maxm], dist[maxn][maxn]; 
int n;
vector<pair<float,float>> points;

float f(pair<float,float> x, pair<float,float> y){
    return sqrt((x.first-y.first)*(x.first-y.first) +  (x.second-y.second)*(x.second-y.second));
}

float solve(int i, int msk){
    if(i==0 && msk==0)
        return 0;
    if(dp[i][msk]>=0)
        return dp[i][msk];
    dp[i][msk] = 1e15;

    for(int j=0;j<n;j++){
        if(msk&(1<<j)){
            dp[i][msk] = min(dp[i][msk],solve(j,msk^(1<<j))+dist[i][j]);
        }
    }

    return dp[i][msk];
}


int main(){
    int x, y;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x >> y;
        points.push_back({x,y});
    }

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            dist[i][j] = f(points[i],points[j]);

    memset(dp,-1,sizeof(dp));
    cout << fixed << setprecision(8) << solve(0,(((1<<n)-1))) << '\n';

    return 0;
}