#include<bits/stdc++.h>
#define maxn int(1e3+3)
#define ll long long
using namespace std;

const ll mod = 998244353;
ll fat[maxn];


int main(){
    int t;

    fat[0] = fat[1] = 1;
    for(int i=2;i<maxn;i++)
        fat[i] = (i*fat[i-1])%mod;

    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll answ = ((n%2) ? 0 : (fat[n/2]*fat[n/2])%mod);
        cout << answ <<"\n";
    }


    return 0;
}