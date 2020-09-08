#include<bits/stdc++.h>
using namespace std;

int n, m, k, x, y;
vector<pair<int,int>> p;
vector<int> col, row;

int main(){
    cin >> n >> m >> k;
    row.assign(n+1,0);
    col.assign(m+1,0);
    
    int mxr = 0, mxc=0;
    for(int i=0;i<k;i++){
        cin >> x >> y;
        p.push_back({x,y});
        row[x]++; col[y]++;
        mxr = max(row[x],mxr);
        mxc = max(col[y],mxc);
    }

    int qtd=0, qtdr=0, qtdc=0;
    for(int i=0;i<=n;i++)
        if(row[i]==mxr)
            qtdr++;
    
    for(int i=0;i<=m;i++)
        if(col[i]==mxc)
            qtdc++;

    for(auto par:p){
        if(row[par.first]==mxr && col[par.second]==mxc){
            qtd++;
        }
    }

    if(qtd == qtdr*qtdc)
        cout << mxr+mxc-1 << '\n';
    else
        cout << mxr+mxc << '\n';

    return 0;
}
