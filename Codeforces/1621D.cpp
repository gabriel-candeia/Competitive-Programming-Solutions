#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll inf = 1e17;

int main(){
    int t;

     cin >> t;
     while(t--){
        int n;
        vector<vector<ll>> cost;

        cin >> n;
        cost.assign(2*n+1,vector<ll>(2*n+1,0));

        for(int i=0;i<2*n;i++){
            for(int j=0;j<2*n;j++){
                cin >> cost[i][j];
            }
        }
        
       ll answ = min({cost[0][n],cost[0][2*n-1],cost[n-1][n],cost[n-1][2*n-1]});
       answ = min({answ,cost[n][0], cost[n][n-1],cost[2*n-1][0],cost[2*n-1][n-1]});

        for(int i=n;i<2*n;i++)
            for(int j=n;j<2*n;j++)
                answ += cost[i][j];

        cout << answ <<"\n";
    }

    return 0;
}