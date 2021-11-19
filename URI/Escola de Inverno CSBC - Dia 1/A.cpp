#include<bits/stdc++.h>
#define maxn 105
using namespace std;

const int inf = 1e9;
char mat[maxn][maxn];
int n, m;

bool isok(int x, int y){
    return x>=0 && y>=0 && x<n && y<m;
}

int conv(char c){
    if(c=='.')
        return 1;
    if(c<='9' && c>='1')
        return c-'0';
    else
        return inf;
}

int solve(){
    vector<int> dist(n*m,inf);
    priority_queue<tuple<int,int>> pq;
    int u, d;
    int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
    dist[0] = conv(mat[0][0]);
    pq.push({-dist[0],0});
    while(pq.size()){
        tie(d, u) = pq.top(), pq.pop();
        int ux = u/m, uy = u%m;
        d = -d;
        if(d>dist[u]) continue;
        for(int i=0;i<4;i++){
            if(isok(ux+dx[i],uy+dy[i]) && d+conv(mat[ux+dx[i]][uy+dy[i]]) < dist[(ux+dx[i])*m+(uy+dy[i])]){
                dist[(ux+dx[i])*m+(uy+dy[i])] = d+conv(mat[ux+dx[i]][uy+dy[i]]);
                pq.push(tuple<int,int>{-dist[(ux+dx[i])*m+(uy+dy[i])],(ux+dx[i])*m+(uy+dy[i])});
            }
        }
    }
    return dist[(n-1)*(m)+m-1];
}

int main(){
    int t;

    cin >> t;
    while(t--){
        
        cin >> n >> m;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)    
                cin >> mat[i][j];
        int answ = solve();
        if(answ == inf)
            answ = -1;
        cout << answ << "\n";
    }

    return 0;

}