#include<bits/stdc++.h>
#define maxn 2005
#define maxm 30
using namespace std;

char grid[maxn*maxn];
vector<int> ls[maxm];
int h, w, visited[maxn*maxn];

int isok(int i, int j){
    return 0<=i && 0<=j && i<h && j<w && grid[i*w+j]!='#' && visited[i*w+j]==-1;
}

int main(){ 
    int start=-1, last=-1;
    cin >> h >> w;
    for(int i=0;i<w*h;i++){
        cin >> grid[i];
        if(grid[i]>='a' && grid[i]<='z')
            ls[grid[i]-'a'].push_back(i);
        if(grid[i]=='S')
            start = i;
        if(grid[i]=='G')
            last = i;
    }
    memset(visited,-1,sizeof(visited));
    queue<int> q; q.push(start); visited[start] = 0;
    while(q.size()){
        int i, j, u;
        u = q.front(); i = u/w; j = u%w; q.pop();
        if(grid[u]>='a' && grid[u]<='z'){
            for(auto pos:ls[grid[u]-'a']){
                grid[pos] = '#';
                if(visited[pos]!=-1) continue;
                q.push(pos);
                visited[pos] = visited[u]+1;
            }
        }

        int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
        for(int k=0;k<4;k++){
            if(isok(i+dx[k],j+dy[k])){
                q.push((i+dx[k])*w+j+dy[k]);
                visited[(i+dx[k])*w+j+dy[k]] = visited[u]+1;
            }
        }               
    }

    cout << visited[last] <<'\n';

    return 0;
}