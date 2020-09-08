#include<bits/stdc++.h>
#define ll long long
#define N 2
using namespace std;

const ll mod = 1e6;
ll n, k, l;
void mult(ll a[N][N], ll b[N][N]){
    ll c[N][N], d[N][N];
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            c[i][j] = a[i][j];
            d[i][j] = b[i][j];
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            a[i][j] = 0;
            for(int k=0;k<2;k++){
                a[i][j] =(a[i][j] + c[i][k]*d[k][j])%mod;
            }
        }
    }
}

ll binpow(ll n){
    if(n<=1)
        return (n==0) ? 1 : k;
    ll mat[N][N] = {{k,l},{1,0}};
    ll result[N][N] = {{1,0},{0,1}};
    n-=1;
    while(n){
        if(n%2)
            mult(result,mat);
        mult(mat,mat);
        n>>=1;
    }
    return (k*result[0][0] + 1*result[0][1])%mod;
}   

int main(){
    
    while(cin >> n >> k >> l){
        n/=5;
        k%=mod; l%=mod;
        printf("%.6lld\n",binpow(n));
    }

    return 0;
}