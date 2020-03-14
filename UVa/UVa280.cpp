#include<bits/stdc++.h>
using namespace std;

int cont;

void dfs(vector<vector<int>>& adj, int root , vector<bool>& visited){
    for(auto i:adj[root]){
        if(!visited[i]){
            visited[i] = true;
            cont --;
            dfs(adj,i,visited);
        }
    }
}

void reach(vector<vector<int>> adj, int n, int root){
    vector<bool> visited; visited.assign(n+1, false);

    cont = n; visited[0] = true;

    dfs(adj, root, visited);
    cout << cont;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            cout << ' ' << i;
        }
    }
    cout << '\n';
}

int main(){
    int n, root, aux, q;
    vector<vector<int>> adj;

    while(true){
        cin >> n;
        if(n==0){ break;}
        adj.assign(n+2,vector<int>());
        while(true){
            cin >> root;
            if(root==0){
                break;
            }
            do{
                cin >> aux;
                adj[root].push_back(aux);
            }while(aux!=0);
        }
        cin >> q;
        while(q--){
            cin >> root;
            reach(adj,n,root);
        }

    }

    return 0;
}
