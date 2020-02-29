#include<bits/stdc++.h>
#define N 100000+3
using namespace std;
vector<pair<int,int>> mat[N];

int main(){
    int n, m, qtd, x;
    char a1[1002], a2[1002];  
    stringstream s1, s2;

    while(cin>>n>>m){
        for(int i=0;i<=m;i++){
            mat[i].clear();
        }
        
        for(int i=0, j;i<n;i++){
            scanf(" %[^\n]s",a1);
            s1 = stringstream(string(a1));
            s1 >> qtd;
            if(qtd){
                scanf(" %[^\n]s",a2);
                s2 = stringstream(string(a2));
            }
            while(qtd--){
                s1 >> j;
                s2 >> x;
                mat[j].push_back(make_pair(i,x));
            }
        }
        cout << m << " " << n << '\n';
        for(int i=1;i<=m;i++){
            cout << mat[i].size();
            for(int j=0;j<mat[i].size();j++){
                cout <<  ' ' << mat[i][j].first+1;
            }
            cout << '\n';
            for(int j=0;j<mat[i].size();j++){
                cout << mat[i][j].second;
                if(j!=mat[i].size()-1){
                    cout << ' ';
                }
            }
            cout << '\n';
        }
    }

    return 0;
}
