#include<bits/stdc++.h>
#define N 300
using namespace std;

vector<bool> visited;

void dfs(vector<int> adj[], int u, int v, int k, int h){
    vector<int> distances; distances.assign(300,0);
    while(true){
        if(h && h%k==0){
            printf("%c ",u);
            visited[u] = true;
        }
        bool flag = true;
        for(auto i:adj[v]){
            if(i!=u && visited[i]==false){
                //dfs(adj,v,i,k,h+1);
                h++;
                u = v; v = i;
                flag = false;
                break;
            }
        }
        if(flag){
            printf("/%c\n",v);
            break;
        }
    }
}

void dfs_wrapper(vector<int> adj[], int u, int v, int k){
    visited.assign(300,false);
    dfs(adj,u,v,k,0);
}

int main(){
    char a, b=0, c;
    int k;

    while(true){
        vector<int> adj[N];
        b = 0;
        while(true){
            if(b=='.'){
                break;
            }
            cin >> a;
            if(a=='#'){ return 0;}
            else{
                cin >> b >> b;
                while(b!=';' && b!='.'){
                    adj[a].push_back(b);
                    cin >> b;   
                }
            }
        }
        if(a=='#'){ return 0;}
        cin >> a >> b >> k;
        dfs_wrapper(adj,b,a,k);
    }

    return 0;
}
