#include<bits/stdc++.h>
#define ll long long
#define maxn int(1e6+5)
#define maxm int(3)

const ll mod = 998244353;
ll c, n, k; 
ll dp[maxn][maxm];


int solve(int i, int qtd){
    if(i==n)
        return 1;
    auto &val = dp[i][qtd];
    if(val!=-1)
        return val;
    if(qtd==0){
        val = (c*solve(i+1,1))%mod;
    }
    else if(qtd==1){
        val = ((c-1)*solve(i+1,2) + solve(i+1,1))%mod;
    }
    else{

    }

    return val;
}

int main(){



}