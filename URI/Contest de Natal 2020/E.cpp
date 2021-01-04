#include<bits/stdc++.h>
#define maxn int(1e4+5)
using namespace std;


int parent[maxn],rnk[maxn];
int find(int x){
    return ((parent[x]==x) ? x : parent[x] = find(parent[x]));
}

void _union(int x, int y){
    x = find(x); y  = find(y);
    if(x!=y){
        if(rnk[x]>rnk[y]){
            parent[y] = x;
        }
        else{
            parent[x] = y;
            rnk[y] += (rnk[x]==rnk[y]);
        }
    }
}


int main(){
    int n, l;

    cin >> n >> l;
    for(int i=0;i<=n;i++){
        rnk[i] = 0;
        parent[i] = i;
    }

    for(int i=0;i<l;i++){
        int x, y;
        cin >> x >> y;
        _union(x,y);
    }
    
    bool poss = true;
    for(int i=1;i<=n;i++)
        poss = (poss && (find(i)==find(1)));
    
    if(poss)
        cout <<"COMPLETO\n";
    else
        cout <<"INCOMPLETO\n";

    return 0;
}