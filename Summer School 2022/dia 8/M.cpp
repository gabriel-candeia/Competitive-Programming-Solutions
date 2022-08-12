#include<bits/stdc++.h>
#define maxm int(1e6+5)
#define maxn int(505)
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

struct dsu{
    vector<int> parent, rnk;

    dsu(int n){
        parent.assign(n+1,0), rnk.assign(n+1,0);
        for(int i=0;i<=n;i++)
            parent[i] = i;
    }

    int find(int x){
        return ((x==parent[x]) ? x : (parent[x] = find(parent[x])));
    }

    void _union(int x, int y){
        x = find(x), y = find(y);
        if(x!=y){
            if(rnk[x]>rnk[y]) swap(x,y);
            parent[x] = y;
            rnk[y] += (rnk[y]==rnk[x]);
        }
    }
};

int n, m, q;
int mat[maxn][maxn];
vector<pair<int,int>> vertices[maxm], queries;
vector<int> lista[maxm];
int L[maxm], R[maxm], answ[maxm];
int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};

bool isok(int x, int y){
    return ((x>=0) && (y>=0) && (x<n) && (y<m));
}

int cnvrt(int x, int y){
    return x*m + y;
}

void resolve(){
    for(int k=0;k<21;k++){
        for(int i=0;i<maxm;i++) 
            lista[i].clear();

        for(int i=0;i<q;i++){
            if(L[i]<=R[i]){
                lista[(R[i] + L[i])/2].push_back(i);
            }
        }
        
        dsu st(n*m);
        for(int i=0;i<maxm;i++){

            for(auto p:vertices[i]){
                int x = p.first, y = p.second;
                for(int inc=0;inc<4;inc++){
                    int nx = x+dx[inc], ny = y + dy[inc];
                    if(isok(nx,ny) && mat[nx][ny]<=i){
                        st._union(cnvrt(nx,ny),cnvrt(x,y));
                    }
                }
            }
            
            for(auto x:lista[i]){
                if(st.find(queries[x].first)==st.find(queries[x].second)){
                    answ[x] = i;
                    R[x] = i-1;
                }
                else{
                    L[x] = i+1;
                }
            }
        }
    }
}

int main(){
    fastio();
    cin >> n >> m >> q;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mat[i][j];
            vertices[mat[i][j]].push_back({i,j});
        }
    }

    for(int i=0;i<q;i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--, c--, d--;
        queries.push_back({cnvrt(a,b),cnvrt(c,d)});
    }

    for(int i=0;i<q;i++){
        L[i] = 1;
        R[i] = maxm-1;
        answ[i] = -1;
    }

    resolve();
    for(int i=0;i<q;i++){
        if(queries[i].first==queries[i].second){
            answ[i] = mat[queries[i].first/m][queries[i].first%m];
        }
        cout << answ[i] << "\n";
    }

    return 0;
}