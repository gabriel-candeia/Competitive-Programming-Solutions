#include<bits/stdc++.h>
#define ll long long
#define maxn int(2e5+5)
using namespace std;

vector<int> adj[maxn];
vector<int> dist;

int solve(int s, int k){
    vector<int> answ;
    queue<int> q;
    k++;
    q.push(s);
    dist[s] = 1;
    while(q.size()){
        tie(s) = q.front(), q.pop();
        answ.push_back(s);
        if(dist[s]==k) continue;
        for(auto v:adj[s]){
            if(!dist[v]){
                q.push(v);
                dist[v] = dist[s]+1;
            }
        }
    }
    int acm = 0;
    for(auto x:answ)
        dist[x] = 0, acm += x;
    return acm;
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dist.assign(n+1,0);
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int a, b;
        cin >> a >> b;
        auto answ = solve(a,b);
        cout << answ <<"\n";
    }

    return 0;
}