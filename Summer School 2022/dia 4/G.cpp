#include<bits/stdc++.h>
#define maxn int(500)
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")

int mat[maxn][maxn], dg[maxn];
set<tuple<int,int,int>> st;

const int inf = 4000;

int main(){
    int n, m;

    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        dg[a]++;
        dg[b]++;
        mat[a][b] = mat[b][a] = -inf;
    }



    for(int i=0;i<n;i++){
        mat[i][i] = -inf;
        for(int j=i+1;j<n;j++){
            if(mat[i][j]!=-inf){
                mat[i][j] = dg[i]+dg[j];
                st.insert(tuple<int,int,int>{mat[i][j],i,j});
            }
        }   
    }
    
    int answ =  2*n;
    int d, u, v;
    while(st.size()){
        tie(d,u,v) = (*st.rbegin());
        st.erase(*st.rbegin());
        if(d>=0)
            answ = min(d,answ);
        //cout <<d<<" "<< u << " "<< v<<"\n";
        int a, b;
        mat[u][v] = -inf;
        for(int j=0;j<n;j++){
            a = min(j,u), b = max(u, j);
            if(mat[a][b]==-inf) continue;
            auto it = st.find(tuple<int,int,int>{mat[a][b],a,b});
            if(it!=st.end())
                st.erase(it);
            mat[a][b]++;
            st.insert({mat[a][b],a,b});
        }
        swap(u,v);
        for(int j=0;j<n;j++){
            a = min(j,u), b = max(u, j);
            if(mat[a][b]==-inf) continue;
            auto it = st.find(tuple<int,int,int>{mat[a][b],a,b});
            if(it!=st.end())
                st.erase(it);
            mat[a][b]++;
            st.insert({mat[a][b],a,b});
        }
    }

    cout << answ <<"\n";

    return 0;
}