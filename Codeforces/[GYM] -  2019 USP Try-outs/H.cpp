#include<bits/stdc++.h>
#define maxn 105
using namespace std;

int notas[maxn][maxn], n, m;
vector<vector<pair<int,int>>> adj;

int comp(int i, int j){
    int answ=0, flag = 0;
    for(int k=0;k<m;k++){
        if(notas[i][k]>=0 && notas[j][k]>=0){
            answ += (notas[i][k]-notas[j][k])*(notas[i][k]-notas[j][k]);
            flag = 1;
        }
    }

    if(flag==0)
        return 1<<30;
    return answ;
}

int selection(int i, int j){
    int answ = -1, mx=0;
    for(int k=0;k<m;k++)
        if(notas[j][k]>=0 && notas[i][k]<0)
            mx = max(mx,notas[j][k]);
    
    for(int k=0;k<m;k++)
        if(notas[j][k]>=0 && notas[i][k]<0 && mx==notas[j][k])
            return k+1;

    return -1;
}


int main(){
    memset(notas,-1,sizeof(notas));
    cin >> n >> m;
    
    int q, x, y;
    for(int i=0;i<n;i++){
        cin >> q;
        for(int j=0;j<q;j++){
            cin >> x >> y;
            notas[i][x-1] = y;
        }
    }

    int w = 0;
    //adj.assign(n+1,vector<pair<int,int>>());
    vector<int> dist(n,1<<30), target(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) continue;
            w = comp(i,j);
            if(w<dist[i]){
                dist[i] = w;
                target[i] = j;
            }
        }
    }
    //cout << dist[0] << " " << target[0] << '\n';
    for(int i=0;i<n;i++){
        cout << selection(i,target[i]) << "\n";
    }
    
    return 0;
}

/*
2 4

3
1 7
2 8
3 10

3
5 6
4 10
2 9
1 5

d[1][2] = (7-5)*(7-5) + (9-8)*(9-8) = alguma_coisa


Among the courses already taken by the closest student, we recommend the course with the 
highest grade which was not already taken by the original student
*/