#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main(){
    int t;

    cin >> t;
    while(t--){
        string s, t;
        int n, m;

        cin >> s >> t;
        n = s.size(); m = t.size();

        vector<vector<int>> mat(n+1,vector<int>(26,INF));

        for(int i=0;i<n;i++){
            mat[i][s[i]-'a'] = i;
        }

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<26;j++){
                mat[i][j] = min(mat[i][j],mat[i+1][j]);
            }
        }
/*
        for(int i=0;i<n;i++){
            for(int j='t'-'a';j<26;j++){
                if(mat[i][j]!=INF){
                    printf("%2d ",mat[i][j]);
                }
                else{
                    printf(".. ");
                }
            }
            printf("\n");
        }*/

        int answ=1, pos = 0;
        bool cond = true;
        for(int i = 0;i<m;i++){
            if(mat[0][t[i]-'a']>=INF){
                cond = false;
                break;
            }
            pos = mat[pos][t[i]-'a']+1;
            if(pos>=INF){
                answ++;
                pos = mat[0][t[i]-'a']+1;
            }
        }
        if(cond){
            cout << answ << '\n';
        }
        else{
            cout << -1 << '\n';
        }
    }

    return 0;
}