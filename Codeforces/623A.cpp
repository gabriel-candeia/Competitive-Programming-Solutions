#include<bits/stdc++.h>
#define N 500
using namespace std;

int main(){
    int n, m, mat[N][N], a, b;
    vector<char> color;
    vector<int> dg;

    cin >> n >> m;
    color.assign(n,'c');
    dg.assign(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat[i][j] = 0;
        }
    }

    for(int i=0;i<m;i++){
        cin >> a >> b;
        a--; b--;
        mat[a][b] = 1;
        mat[b][a] = 1;
        dg[b]++; dg[a]++;
        if(dg[a]==n-1){
            color[a] = 'b';
        }
        if(dg[b]==n-1){
            color[b] = 'b';
        }
    }    

    for(int i=0;i<n;i++){
        if(color[i]=='c'){
            color[i]='a';
            for(int j=0;j<n;j++){
                if(mat[i][j] && color[j]=='c'){
                    color[j] = 'a';
                }
            }
            break;
        }
    }

    bool poss = true;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){   
            if((abs(color[i]-color[j])>1 && mat[i][j]) || (abs(color[i]-color[j])<=1 && !mat[i][j])){
                poss = false;
            }
        }
    }


    if(poss){
        cout << "YES\n";
        for(int i=0;i<n;i++){
            cout << color[i];
        }
        cout << '\n';
    }
    else{
        cout << "NO\n";
    }

    return 0;
}