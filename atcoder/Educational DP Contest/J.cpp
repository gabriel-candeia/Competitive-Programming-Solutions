#include<bits/stdc++.h>
#define ld long double
#define maxn 305
using namespace std;

int n;
ld memo[maxn][maxn][maxn];

ld solve(int x, int y, int z){
    if(x<0 || y<0 || z<0)
        return 0;    
    if(memo[x][y][z]>=0)
        return memo[x][y][z];
    if(x+y+z==0)
        return memo[x][y][z] = 0;
    int empty = n-x-y-z;
    ld p[4] = {1.0*empty/n,1.0*x/n,1.0*y/n,1.0*z/n};
    return memo[x][y][z] = (1.0 + p[1]*solve(x-1,y,z) + p[2]*solve(x+1,y-1,z) + p[3]*solve(x,y+1,z-1))/(1-p[0]);
}

int main(){
    cin >> n;
    int cnt[4] = {0,0,0,0}, y;
    memset(memo,-1,sizeof(memo));
    for(int i=0;i<n;i++){
        cin >> y;
        cnt[y]++;
    }
    cout << setprecision(15)<< solve(cnt[1],cnt[2],cnt[3]) <<'\n';
    return 0;
}