#include<bits/stdc++.h>
#define maxn 60
#define ll long long
using namespace std;

const ll inf = 1e9;
char mat[maxn][maxn];

int main(){
    int t, caso = 0;

    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<ll> row(n,0), col(n,0);

        char x;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> x;
                mat[i][j] = x;
                if(x=='O')
                    row[i] = inf, col[j] = inf;
                else if(x=='.')
                    row[i]++, col[j]++;
            }
        }

        ll min = inf;
        for(int i=0;i<n;i++){
            if(row[i]<min)
                min = row[i];
            if(col[i]<min)
                min = col[i];
        }

        if(min>=inf){
            cout <<"Case #" << ++caso << ": " << "Impossible" << "\n";
        }
        else{
            ll answ = 0;
            for(int i=0;i<n;i++)
                answ+=(row[i]==min), answ+=(col[i]==min);

            if(min==1){
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        if(mat[i][j]=='.' && row[i]==1 && col[j]==1){
                            answ--;
                        }
                    }
                }
            }
            
            cout <<"Case #" << ++caso << ": " << min << " " << answ << "\n";
        }

    }

    return 0;
}