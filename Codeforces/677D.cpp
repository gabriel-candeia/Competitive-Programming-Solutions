#include<bits/stdc++.h>
#define ll long long
#define maxn int(300+5)
#define maxm int(9e4+5)
using namespace std;

ll dist[maxn][maxn], d[maxn][maxn];
ll n, m, lim, x;
vector<pair<ll,ll>> arr[maxm];

bool isok(int x, int y){
    return (x>0 && y>0 && x<=n && y<=m);
}

int main(){
    cin >> n >> m >> lim;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> x;
            arr[x].push_back({i,j});
        }
    }

    for(int i=0;i<maxn;i++)
        for(int j=0;j<maxn;j++)
            dist[i][j] = 1e17;

    for(auto p:arr[1])
        dist[p.first][p.second] = abs(p.first-1)+abs(p.second-1);
    
    for(int i=1;i<lim;i++){
        if(arr[i].size()*arr[i+1].size()<=n*m){
            for(auto p:arr[i])
                for(auto q:arr[i+1])
                    dist[q.first][q.second] = min(dist[q.first][q.second],abs(p.first-q.first)+abs(p.second-q.second)+dist[p.first][p.second]);
        }
        else{
            for(int j=0;j<=n;j++)
                for(int k=0;k<=m;k++)
                    d[j][k] = -1;

            vector<tuple<ll,ll,ll>> last;
            queue<tuple<ll,ll,ll>> q;
            ll val, x, y;
            int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

            for(auto p:arr[i])
                last.push_back({dist[p.first][p.second],p.first,p.second});
            sort(last.rbegin(),last.rend());

            tie(val,x,y) = last.back(); 
            q.push(last.back()); last.pop_back();
            d[x][y] = val;
            
            while(q.size()){
                tie(val,x,y) = q.front(); q.pop();
                
                while(last.size() && get<0>(last.back())==val){
                    d[get<1>(last.back())][get<2>(last.back())] = val;
                    q.push(last.back());
                    last.pop_back();
                }

                for(int k=0;k<4;k++){
                    if(isok(x+dx[k], y+dy[k]) && d[x+dx[k]][y+dy[k]]==-1){
                        d[x+dx[k]][y+dy[k]] = val+1;
                        q.push({val+1,x+dx[k],y+dy[k]});
                    }
                }
            }

            for(auto p:arr[i+1])
                dist[p.first][p.second] = d[p.first][p.second];
            
        }
    }

    
    cout << dist[arr[lim][0].first][arr[lim][0].second] << '\n';

    return 0;
}