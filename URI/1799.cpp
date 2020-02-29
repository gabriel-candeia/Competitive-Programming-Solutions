#include<bits/stdc++.h>
#define N 4000+3
using namespace std;

int dist(vector<int> edges[N], int n, int u, int v){
    vector<bool> visited; visited.assign(n+1,false);
    vector<int> dist; dist.assign(n+1,0);
    int st[N], top = 0, head = 0, z;

    visited[u] = true;
    st[top++] = u;
    dist[u] = 0;
    while(head!=top){
        z = st[head++];
        for(auto i:edges[z]){
            if(!visited[i]){
                dist[i] = dist[z]+1;
                visited[i] = true;
                st[top++] = i;
            }
        }
    }
    return dist[v];
}

int main(){
    vector<int> edges[N];
    map<string,int> id;
    string s1, s2;
    int n, m, count=1;

    cin >> n >>m;
    while(m--){
        cin >> s1 >> s2;
        if(!id[s1]){
            id[s1] = count++;
        }
        if(!id[s2]){
            id[s2] = count++;
        }
        edges[id[s1]].push_back(id[s2]);
        edges[id[s2]].push_back(id[s1]);
    }

    cout << dist(edges,n,id["Entrada"],id["*"]) + dist(edges,n,id["*"],id["Saida"])<< '\n';

    return 0;
}
