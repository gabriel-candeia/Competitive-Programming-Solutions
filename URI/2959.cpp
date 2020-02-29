#include<bits/stdc++.h>
#define N 400+3
using namespace std;

int parent[N], _rank[N];
int n, m, p, x, y;

int find(int x){
    int v = x, next;
    while(parent[v]!=v){
        v = parent[v];
    }
    while(parent[x]!=x){
        next = parent[x];
        parent[x] = v;
        x = next;
    }
    return v;
}

void _union(int x, int y){
    x = find(x);
    y = find(y);
    if(x!=y){
        if(_rank[x]<_rank[y]){
            parent[y] = x;
            _rank[x]+=_rank[y];
        }
        else{
            parent[x] = y;
            _rank[y]+=_rank[x];
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> p;
    for(int i=1;i<=n;i++){
        parent[i] = i;
        _rank[i] = 1;
    }
    while(m--){
        cin >> x >> y;
        _union(x,y);
    }
    while(p--){
        cin >> x >> y;
        cout << ((find(x)==find(y)) ? "Lets que lets\n" : "Deu ruim\n");
    }

    return 0;
}
