#include<bits/stdc++.h>
#define maxn int(1e3+5)
using namespace std;

int mat[maxn][maxn], prefixo[2][maxn][maxn], mn[maxn][20], n, m, temp[maxn][maxn];

int query(int l, int x){
    int answ = 1e6;
    if(l+x>n)
        return -1;
    for(int k=19;k>=0;k--){
        if(x>=(1<<k)){
            answ = min(answ,mn[l][k]);
            l+=(1<<k);
            x-=(1<<k);
        }
    }
    return answ;
}

int bb(int j){
    int l=0, r=n, answ=0, med=0, cmp;
    while(l<=r){
        med = l +(r-l)/2;
        cmp = query(j,med);
        if(cmp>=med){
            answ = med;
            l = med+1;
        }
        else{
            r = med-1;
        }
    }
    return answ;
}

int main(){

    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;
            cin >> c;
            mat[i][j] = ((c=='G') ? 1 : 0);
        }
    }

    for(int k=0;k<2;k++){
        for(int i=0;i<n;i++){
            int last = (mat[i][m-1]==k);
            for(int j=m-1;j>=0;j--){
                if(mat[i][j]!=k)
                    last = 0;
                prefixo[k][i][j] = last++;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            prefixo[0][i][j] = max(prefixo[0][i][j],prefixo[1][i][j]);
          //  cout << prefixo[0][i][j] << " ";
        }
        //cout<<'\n';
    }

    int answ = 0;
    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++)
            mn[i][0] = prefixo[0][i][j];
        for(int k=1;k<20;k++)
            for(int i=0;i+(1<<k)<=n;i++)
                mn[i][k] = min(mn[i][k-1],mn[i+(1<<(k-1))][k-1]);
        for(int i=0;i<n;i++){
            int x = bb(i);
            answ = max(answ,x*x);
        }
    }

    cout << answ <<'\n';

    return 0;
}

