#include<bits/stdc++.h>
#define N 40
using namespace std;

int memo[N][N];
bool ehPossivel(int x, int n, int m){
    if(x<=0){
        return true;
    }
    if(n==0 && m==0){
        return false;    
    }
    bool p1 = false, p2 = false;
    if(n!=0){
        if(memo[n-1][m]==-1){
            memo[n-1][m] = ehPossivel((x/2)+10,n-1,m);
        }
        p1 = memo[n-1][m];
    }
    if(m!=0){
        if(memo[n][m-1]==-1){
            memo[n][m-1] = ehPossivel(x-10,n,m-1);
        }
        p2 = memo[n][m-1];
    }
    return (p1 || p2);
}

int main(){
    int t, x, n, m;

    cin >> t;
    while(t--){
        cin >> x >> n >> m;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                memo[i][j] = -1;
            }    
        }
        cout << (ehPossivel(x,n,m) ? "YES" : "NO") << '\n';
    }
    return 0;
}
