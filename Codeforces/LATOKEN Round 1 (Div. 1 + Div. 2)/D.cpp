#include<bits/stdc++.h>
#define maxn int(2005)
using namespace std;

int n;
vector<int> visited;

int isleaf(vector<int> &dist){
    int last = -1;
    for(int i=1;i<=n;i++){
        if(dist[i]==1 && last==-1)
            last = i;
        else if(dist[i]==1 && last!=-1)
            return -1;
    }
    return last;
}

int edges[maxn][maxn];

int main(){
    cin >> n;
    visited.assign(n+1,0);
    vector<int> d(n+1,0), q;
    int odd=0;

    cout << "? " << 1 << endl;
    for(int i=1;i<=n;i++) cin >> d[i];
    for(int i=2;i<=n;i++) odd+=d[i]%2;

    odd = (odd<n/2) ? 1 : 0;

    for(int i=2;i<=n;i++) if(d[i]%2==odd) q.push_back(i);
    for(int i=1;i<=n;i++) if(d[i]==1) edges[1][i] = 1;

    for(auto x:q){
        cout << "? " << x << endl;

        
        for(int i=1;i<=n;i++) cin >> d[i];
        
        for(int i=1;i<=n;i++) if(d[i]==1) edges[min(x,i)][max(x,i)] = 1;
        
    }

    cout << "!" << endl;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(edges[i][j])
                cout << i << " " << j << endl;

    return 0;
}