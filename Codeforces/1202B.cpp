#include<bits/stdc++.h>
using namespace std;

int mat[10][10][10][10];
int visited[10];
queue<int> q;

int bfs(int u,int i,int j){
    for(int k=0;k<10;k++){ 
        visited[k] = 0;
    }
    int dist = 0;
    q.push(u);
    int w;
    while(q.size()){
        w = q.front(); q.pop();
        dist = visited[w];
        if(!visited[(w+i)%10]){
            visited[(w+i)%10] = dist+1;
            q.push((w+i)%10);
        }
        if(!visited[(w+j)%10]){
            visited[(w+j)%10] = dist+1;
            q.push((w+j)%10);
        }
    }
    for(int k=0;k<10;k++){
        mat[u][i][j][k] = visited[k];
    }
}

int cost(string s, int i, int j){
    int current = 0, answ=0;
    int next;
    for(int k=1;k<s.size();k++){
        next = s[k]-'0';
        if(mat[current][i][j][next]==0){
            return -1;
        }
        answ += mat[current][i][j][next]-1;
        current = next;
    }
    return answ;
}

int main(){
    string s;
    
    cin >> s;

    for(int u=0;u<10;u++){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                bfs(u,i,j);
            }
        }
    }

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout << cost(s,i,j) << ' ';
        }
        cout << '\n';
    }
    return 0;
}   