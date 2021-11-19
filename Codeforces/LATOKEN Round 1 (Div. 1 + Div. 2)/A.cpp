#include<bits/stdc++.h>
#define maxn 50
using namespace std;

char mat[maxn][maxn], answ[maxn][maxn];
int main(){
    int t;

    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin >> mat[i][j];

        for(int i=0;i<n;i++){
            char last = (i%2) ? 'R' : 'W';
            for(int j=0;j<m;j++){
                answ[i][j] = last;
                last = (last=='R') ? 'W' : 'R';
            }
        }

        bool ok = true;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(mat[i][j]!='.' && mat[i][j]!=answ[i][j])
                   ok = false;
  
        if(!ok){
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                    answ[i][j] = ((answ[i][j]=='R') ? 'W' : 'R');
            ok = true;
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                    if(mat[i][j]!='.' && mat[i][j]!=answ[i][j])
                    ok = false;
        }   

     
        if(ok){
            cout << "YES\n";
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++)
                    cout << answ[i][j] << "";
                cout<<'\n';
            }
        }
        else{
            cout <<"NO\n";
        }

    }

    return 0;
}