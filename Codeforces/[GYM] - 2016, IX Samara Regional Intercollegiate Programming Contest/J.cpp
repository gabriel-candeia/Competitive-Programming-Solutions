#include <bits/stdc++.h>
#define ii array<int,2>
using namespace std;

vector<vector<char>> matrix;

ii mov[] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
vector<vector<bool>> vis;
vector<vector<int>> grau;
vector<vector<ii>> pos; // ii pos[maxn][maxn]

int n, m;

bool ciclo = false;
void dfs(ii s) {
    vis[s[0]][s[1]] = 1;
    ciclo |= (grau[s[0]][s[1]] >=3);
    for(auto [x, y] : mov) {
        x += s[0];
        y += s[1];
        if(x >= 0 and x < n and y >= 0 and y < m and matrix[x][y] != '#' and vis[x][y] == 1 and ii{x,y}!=pos[s[0]][s[1]]){
            ciclo = true;
        }
        if(x >= 0 and x < n and y >= 0 and y < m and matrix[x][y] != '#' and vis[x][y] == 0) {
            pos[x][y] = {s[0], s[1]};
            dfs({x, y});
        }
    }
}

int main() {
    cin >> n >> m;

    ii a1, a2;
    matrix.assign(n,vector<char>(m,'0'));
    vis.assign(n,vector<bool>(m,0));
    grau.assign(n,vector<int>(m,0));
    pos.assign(n,vector<ii>(m,{-1,-1}));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matrix[i][j];
            if(matrix[i][j] == '1')
                a1 = {i, j};
            if(matrix[i][j] == '2')
                a2 = {i, j};
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[i][j]=='#') continue;
            for(auto [a, b] : mov){
                a += i;
                b += j;
                if(a >= 0 and a < n and b >= 0 and b < m and matrix[a][b] != '#')
                    grau[i][j]++;
            }
        }
    }

    pos[a1[0]][a1[1]] = {-1,-1};
    dfs(a1);
    bool answ = ciclo;

    if(vis[a2[0]][a2[1]]==0){
        cout << "NO\n";
        return 0;
    }

    cout << (answ ? "YES" : "NO") << '\n';
}