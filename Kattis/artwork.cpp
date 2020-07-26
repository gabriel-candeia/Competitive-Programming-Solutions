 #include<bits/stdc++.h>
 #define N 1005
 using namespace std;

class DSU{
    private:
        vector<int> parent, rank;
        int cc;
    public:
        DSU(int n, int x){
            parent.assign(n+1,0);
            rank.assign(n+1,0);
            cc = x-1;
            for(int i=0;i<=n;i++){
                parent[i] = i;
            }
        }

        int find(int x){
            return ((parent[x] == x) ? x : (parent[x] = find(parent[x])));
        }

        void _union(int x, int y){
            x = find(x); y = find(y);
            if(x!=y){
                cc--;
                if(rank[x]>rank[y]){
                    parent[y] = x;
                }
                else{
                    parent[x] = y;
                    rank[y] += (rank[x]==rank[y]);
                }
            }
        }

        int comp(){
            return cc;
        }
};

 int main(){
    int grid[N][N], n, m, q, black=0;
    int x1, y1, x2, y2;
    vector<tuple<int,int,int,int>> queries;
    vector<int> answ;
    

    cin >> n >> m >> q;
    answ.assign(q,0);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            grid[i][j] = 0;
        }
    }

    for(int i=0;i<=n+1;i++){
        grid[i][0] = 1;
        grid[i][m+1] = 1;
    }

    for(int j=0;j<=m+1;j++){
        grid[0][j] = 1;
        grid[n+1][j] = 1;
    }

    for(int k=0;k<q;k++){
        cin >> x1 >> y1 >> x2 >> y2;
        queries.push_back({x1,y1,x2,y2});
        for(int i=x1;i<=x2;i++){
            for(int j=y1;j<=y2;j++){
                grid[i][j]++;
                black+=(grid[i][j]==1);
            }
        }
    }
    
    DSU alg((n+1)*(m+1),n*m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(grid[i][j]==0){
                if(grid[i+1][j]==0){
                    alg._union(i*m+j,(i+1)*m+j);
                }
                if(grid[i][j+1]==0){
                    alg._union(i*m+j,i*m+j+1);
                }
            }
        }
    }
    
     
    for(int k=q-1;k>=0;k--){
        answ[k] = alg.comp()-black+1;
        tie(x1,y1,x2,y2) = queries[k];
        for(int i=x1;i<=x2;i++){
            for(int j=y1;j<=y2;j++){
                grid[i][j]--;
                black-=(grid[i][j]==0);
            }
        }
        for(int i=x1;i<=x2;i++){
            for(int j=y1;j<=y2;j++){
                if(grid[i][j]==0){
                    if(grid[i+1][j]==0){
                        alg._union(i*m+j,(i+1)*m+j);
                    }
                    if(grid[i][j+1]==0){
                        alg._union(i*m+j,i*m+j+1);
                    }
                    if(grid[i-1][j]==0){
                        alg._union(i*m+j,(i-1)*m+j);
                    }
                    if(grid[i][j-1]==0){
                        alg._union(i*m+j,i*m+j-1);
                    }
                }
            }
        }
    }
    for(int i=0;i<q;i++){
        cout << answ[i] << '\n';
    }

    return 0;
 }