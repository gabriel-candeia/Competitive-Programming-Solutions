#include<bits/stdc++.h>
#define maxn 2005
using namespace std;

int h[maxn][maxn], v[maxn][maxn], n, k, ft[maxn][maxn];
char grid[maxn][maxn];

int lsone(int x){
    return (x&(-x));
}

void update(int i, int r, int v){
    if(!r) return;
    for(;r<maxn;r+=lsone(r))
        ft[i][r] += v;
}

int get(int i, int r){
    int sum=0;
    for(;r;r-=lsone(r))
        sum += ft[i][r];
    return sum;
}

int main(){
    cin >> n >> k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin >> grid[i][j];
    int acm=0;
    for(int j=1;j<=n;j++){
        int lst = 0;
        for(int i=1;i<=n;i++)
            if(grid[i][j]=='B')
                lst = i;
        acm+=(lst==0);
        for(int i=1;i<=n;i++){
            v[i][j] = lst;
            if(grid[i][j]=='B')
                lst = 0;
        }

    }

    for(int i=1;i<=n;i++){
        int lst = 0;
        for(int j=1;j<=n;j++)
            if(grid[i][j]=='B')
                lst = j;
        acm+=(lst==0);
        for(int j=1;j<=n;j++){
            h[i][j] = lst;
            if(grid[i][j]=='B')
                lst = 0;
        }
    }

    int answ = 0;
    for(int j=1;j<=n;j++)
        for(int i=1;i<=k;i++)
            update(j,h[i][j],1);
    
    for(int i=1;i+k-1<=n;i++){
        memset(ft[n+1],0,sizeof(ft[n+1]));
        for(int j=1;j<=k;j++)
            update(n+1,v[i][j],1);

        for(int j=1;j+k-1<=n;j++){
            answ = max(answ,get(j,j+k-1)+get(n+1,i+k-1));
           //cout << get(n+1,i+k-1) <<' ';

            update(n+1,v[i][j],-1);
            update(n+1,v[i][j+k],1);

            update(j,h[i][j],-1);
            update(j,h[i+k][j],1);
        }//cout<<'\n';
    }

    cout << answ+acm <<'\n';

    return 0;
}