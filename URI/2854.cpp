#include<bits/stdc++.h>
#define N 500
using namespace std;

int bfs(vector<int> adj[N], int n){
    int cc=0, top=0, z;
    int stack[N], visited[N];

    for(int i=0;i<=n;i++){
        visited[i] = false;
    }

    for(int i=1;i<=n;i++){
        if(visited[i]==false){
            cc++;
            stack[top++] = i;
            while(top){
                z = stack[--top];
                for(int j=0;j<adj[z].size();j++){
                    if(visited[adj[z][j]]==false){
                        visited[adj[z][j]] = true;
                        stack[top++] = adj[z][j];
                    }
                }
            }
        }
    }
    return cc;
}

int main(){
    vector<int> adj[N];
    map<string, int>  nome;
    int m, n, cont = 1;
    string s1, s3;

    cin >> m >> n;
    while(n--){
        cin >> s1 >> s3 >> s3;
        if(!nome[s1]){
            nome[s1] = cont++;
        }
        if(!nome[s3]){
            nome[s3] = cont++;
        }
        adj[nome[s1]].push_back(nome[s3]);
        adj[nome[s3]].push_back(nome[s1]);
    }
    cout << bfs(adj,m) << '\n';
    return 0;
}
    