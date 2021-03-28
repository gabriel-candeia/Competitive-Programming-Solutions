#include<bits/stdc++.h>
#define maxn int(1e5+5)
using namespace std;

int pref[maxn];
int main(){
    int n, m;
    vector<vector<char>> mat;

    cin >> n >> m;
    mat.assign(n,vector<char>(m,0));
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)    
            cin >> mat[i][j];

    for(int i=0;i<n;i++){
        int last = m;
        for(int j=m-1;j>=0;j--){
            if(mat[i][j]=='+'){
                last = j;
            }
            else{
                pref[1]++;
                pref[last-j+1]--;       
            }
        }
    }

    for(int j=0;j<m;j++){
        int last = n;
        for(int i=n-1;i>=0;i--){
            if(mat[i][j]=='+'){
                last = i;
            }
            else{
                pref[1]++;
                pref[last-i+1]--;       
            }
        }
    }
    
    for(int i=1;i<=max(n,m);i++){
        pref[i] += pref[i-1];
        if(i==1)
            cout << pref[i]/2 << " ";
        else
            cout << pref[i] << " ";
    }
    cout<<'\n';

    return 0;
}

