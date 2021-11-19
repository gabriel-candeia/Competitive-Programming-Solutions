#include<bits/stdc++.h>
#define maxn 150
using namespace std;

char mat[maxn][maxn];
int freq[maxn], answ[maxn];

int comp(char a, char b){
    if((a=='G'&&b=='C') || (a=='C'&&b=='P') || (a=='P'&&b=='G'))
        return 1;
    return 0;
}

int main(){
    int n, m;

    cin >> n >> m;
    for(int i=0;i<2*n;i++){
        for(int j=0;j<m;j++){
            cin >> mat[i][j];   
        }
    }

    vector<pair<int,int>> players;
    for(int i=0;i<2*n;i++){
        players.push_back({-freq[i],i});
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int u = players[2*j].second, v = players[2*j+1].second;
            freq[u] += comp(mat[u][i],mat[v][i]);
            freq[v] += comp(mat[v][i],mat[u][i]);
        }
        for(auto &p:players)
            p.first = -freq[p.second];
        sort(players.begin(),players.end());
    }

    for(auto p:players)
        cout << p.second+1 << "\n";

    return 0;
}