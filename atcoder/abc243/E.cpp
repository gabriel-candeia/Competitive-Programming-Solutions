#include<bits/stdc++.h>
#define maxn 305
#define ll long long
using namespace std;

const ll inf = 1e18;
int n, m;
pair<ll,int> mat[maxn][maxn];

int main(){
    cin >> n >> m;

    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
            mat[i][j] = {inf,0};
    
    vector<array<int,3>> edges(m);

    for(auto &x:edges){
        for(auto &y:x)
            cin >> y;
    }

    for(auto e:edges){
        mat[e[0]][e[1]] = mat[e[1]][e[0]] = min(mat[e[0]][e[1]],{e[2],-1});
    }

    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                mat[i][j] = min(mat[i][j], {mat[i][k].first+mat[k][j].first,mat[i][k].second+mat[k][j].second});

    int answ = 0;
    for(auto e:edges){
        answ += (mat[e[0]][e[1]].first<e[2] ||(mat[e[0]][e[1]].first==e[2] && mat[e[0]][e[1]].second<-1));
    }

    cout << answ <<"\n";

    return 0;
}