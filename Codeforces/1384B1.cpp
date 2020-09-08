#include<bits/stdc++.h>
#define N 205
using namespace std;

int main(){ 
    int t, n, k, l;

    cin >> t;
    while(t--){
        cin >> n >> k >> l;

        queue<tuple<int,int>> q;
        int u, tempo;

        int d[N];
        bool visited[N][N];
        bool poss = false;
        memset(visited, false, sizeof(visited));
        for(int i=1;i<=n;i++){
            cin >> d[i];
        }
        d[0] = -10000;
        d[n+1] = -10000;
        q.push({0,0});
        visited[0][0] = true;

        while(q.size()){
            tie(u,tempo) = q.front(); q.pop();
            if(u==n+1)
                poss = true;

            tempo = (tempo+1)%(2*k);
            int inc = (tempo<k) ? tempo : 2*k-tempo;
            if(!visited[u][tempo] && d[u]+inc<=l){
                visited[u][tempo] = true;
                q.push({u,tempo});
            }
            if(!visited[u+1][tempo] && d[u+1]+inc<=l){
                visited[u+1][tempo] = true;
                q.push({u+1,tempo});
            }
        }
    
        cout << ((poss) ? "Yes" : "No") << '\n';
    }

    return 0;
}