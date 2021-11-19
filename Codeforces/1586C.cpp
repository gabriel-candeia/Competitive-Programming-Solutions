#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    vector<vector<char>> mat;
    vector<int> precomp;

    cin >> n >> m;
    precomp.assign(m,0);
    mat.assign(n,vector<char>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mat[i][j];
        }
    }
    

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            precomp[j] += (mat[i-1][j]=='X' && mat[i][j-1]=='X');
        }
    }
    

    for(int i=1;i<m;i++)
        precomp[i] += precomp[i-1];
    
    int q;
    cin >> q;
    
    while(q--){
        int a, b;
        cin >> a >> b;
        a--, b--;
        bool answ;
        if(a==b)
            answ = 1;
        else{
            answ = ((precomp[b]-precomp[a])==0);
        }

        cout << ((answ) ? "YES" : "NO") <<"\n";
    }

    return 0;
}