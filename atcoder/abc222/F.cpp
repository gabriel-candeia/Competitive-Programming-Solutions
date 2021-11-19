#include<bits/stdc++.h>
#define maxn int(2e5+5)
#define ll long long
using namespace std;

vector<pair<int,int>> adj[maxn];
ll answ[maxn], first[maxn], second[maxn], cost[maxn];

void precomp(int u, int p){
    first[u] = second[u] = 0;
    for(auto e:adj[u]){
        int v = e.first, w = e.second;
        if(v!=p){
            precomp(v,u);
            ll valor = max(first[v],cost[v])+w;
            if(valor>first[u]){
                second[u] = first[u];
                first[u] = valor;
            }
            else if(valor>second[u]){
                second[u] = valor;
            }
        }
    }
}

void solve(int u, int p){
    answ[u] = first[u];
    for(auto e:adj[u]){
        int v = e.first, w = e.second;
        if(v!=p){
            ll oldv1 = first[v], oldv2 = second[v];
            ll outro = first[u];
            if(first[u]==first[v]+w || first[u] == cost[v]+w){
                outro = second[u];
            }
            outro = max(outro,cost[u])+w;

            if(outro>first[v]){
                second[v] = first[v];
                first[v] = outro;
            }
            else if(outro > second[v]){
                second[v] = outro;
            }


            solve(v,u);

            first[v] =  oldv1, second[v] = oldv2;
        }
    }
}

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    for(int i=1;i<=n;i++)
        cin >> cost[i];


    precomp(1,-1);

    solve(1,-1);
    for(int i=1;i<=n;i++)
        cout << answ[i] << "\n";

    return 0;
}