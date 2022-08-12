#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll mat[100][100], pref[100][100];

ll soma(int a, int b, int x, int y){
    return pref[x][y] - pref[a-1][y] - pref[x][b-1] + pref[a-1][b-1];
}

int main(){
    int n, m;

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> mat[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        ll acm = 0;
        for(int j=1;j<=m;j++){
            acm += mat[i][j];
            pref[i][j] = pref[i-1][j] + acm;
        }
    }
    
    ll answ = mat[1][1];
    vector<pair<int,int>> best = {{1,1},{1,1}};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int x=i;x<=n;x++){
                for(int y=j;y<=m;y++){
                    ll novo = max(answ,soma(i,j,x,y));
                    if(novo>answ){
                        answ = novo;
                        best = {{i,j},{x,y}};
                    }
                }   
            }
        }
    }

    cout << answ <<"\n";
    cout << best[0].first << " " << best[0].second <<"\n";
    cout << best[1].first << " " << best[1].second <<"\n";

    return 0;
}