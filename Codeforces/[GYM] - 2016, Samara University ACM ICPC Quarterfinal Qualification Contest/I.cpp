#include<bits/stdc++.h>
#define maxn int(2e5+5)
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

vector<int> adj[maxn];

int main(){
    fastio();
    int n, m;

    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int mn = n+1, best = 0;
    for(int i=1;i<=n;i++){
        if(mn>adj[i].size()){
            mn = adj[i].size();
            best = i;
        }
    }

    vector<int> answ(n+1,1);
    for(auto v:adj[best])
        answ[v] = 0;
    answ[best] = 0;

    for(int i=1;i<=n;i++)
        cout << answ[i] << " ";
    cout<<"\n";


    return 0;
}