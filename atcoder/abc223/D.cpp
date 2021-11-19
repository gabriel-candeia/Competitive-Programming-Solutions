#include<bits/stdc++.h>
#define maxn int(2e5+5)
using namespace std;

vector<int> adj[maxn], dg;

int main(){
    int n, m;

    cin >> n >> m;
    dg.assign(n+1,0);
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        dg[b]++;
    }

    priority_queue<int> pq;
    for(int i=1;i<=n;i++)
        if(dg[i]==0)
            pq.push(-i);

    int u;
    vector<int> answ;
    while(pq.size()){
        u = pq.top(), pq.pop(), u = -u;
        answ.push_back(u);
        for(auto v:adj[u]){
            dg[v]--;
            if(dg[v]==0){
                pq.push(-v);
            }
        }
    }

    if(answ.size()==n){
        for(auto x:answ){
            cout << x << " ";
        }cout<<"\n";
    }
    else{
        cout << -1 << '\n';
    }

    return 0;
}