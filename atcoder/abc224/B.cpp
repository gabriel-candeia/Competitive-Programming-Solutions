#include<bits/stdc++.h>
#define ll long long
#define maxn 100
using namespace std;

ll mat[maxn][maxn];

int main(){
    int n, m;

    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> mat[i][j];

    bool poss = true;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            for(int i1=i+1;i1<n;i1++)
                for(int j1=j+1;j1<m;j1++)
                    if(mat[i][j]+mat[i1][j1] > mat[i][j1]+mat[i1][j])
                        poss = false;

    if(poss)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}