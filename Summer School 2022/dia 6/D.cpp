#include<bits/stdc++.h>
#define ll long long
#define maxn int(2e5+5)
using namespace std;

const ll mod = 998244353;
ll fat[maxn], dg[maxn];


int main(){
    fat[0] = 1;
    for(int i=1;i<maxn;i++) 
        fat[i] = (fat[i-1]*i)%mod;
    
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        dg[a]++;
        dg[b]++;
    }

    ll answ = fat[dg[1]];
    for(int i=2;i<=n;i++){
        answ = (answ*fat[dg[i]])%mod;
    }
    answ = (answ*n)%mod;

    cout << answ <<"\n";
    return 0;
}
