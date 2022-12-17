#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int main(){
    fastio();
    int t, caso=0;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        //cout << n << " " << m <<"\n";
        vector<vector<char>> mat(n,vector<char>(m,0));
        for(auto &row:mat){
            for(auto &el:row){
                cin >> el;
            }
        }

        vector<int> dg(n*m+1,0);
        priority_queue<tuple<int,int,int>> pq;

        auto conv = [=](int i, int j) {return i*m+j;};
        auto isok = [=](int i, int j) {return i>=0 && j>=0 && i<n && j<m;};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='#') continue;
                if(i+1<n && mat[i+1][j]!='#'){
                    dg[conv(i,j)]++;
                    dg[conv(i+1,j)]++;
                }
                if(j+1<m && mat[i][j+1]!='#'){
                    dg[conv(i,j)]++;
                    dg[conv(i,j+1)]++;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='#') continue;
                pq.push({-dg[conv(i,j)],i,j});
            }
        }

        bool answ = true;
        int x, y, d;
        int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
        //cout << pq.size() <<"\n";
        while(pq.size()>0){
            tie(d,x,y) = pq.top(), pq.pop(), d = -d;
            if(d<=1 && mat[x][y]=='^') {answ = false; break;}
            if(d>1) {pq.push({-d,x,y}); break;};
            if(d!=dg[conv(x,y)]) continue;
            
            dg[conv(x,y)] = 0;
            for(int k=0;k<4;k++){
                int nx = x + dx[k], ny = y + dy[k];
                if(isok(nx,ny) && dg[conv(nx,ny)]>0 && mat[nx][ny]!='#'){
                    dg[conv(nx,ny)]--;
                    pq.push({-dg[conv(nx,ny)],nx,ny});
                }
            }
        }
        
        while(pq.size()>0){
            tie(d,x,y) = pq.top(), pq.pop(), d = -d;
            if(d!=dg[conv(x,y)]) continue;
            mat[x][y] = '^';
        }

        cout << "Case #" << ++caso << ": " << ((answ) ? "Possible" : "Impossible") <<"\n";
        if(answ){
            for(auto row:mat){
                for(auto el:row){
                    cout << el;
                }
                cout<<"\n";
            }
        }

    }



    return 0;
}