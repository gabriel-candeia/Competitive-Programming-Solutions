#include<bits/stdc++.h>
    
using namespace std;
    
#define F first
#define S second
#define PB push_back
#define FOR(i,a,b) for(int i = a; i <= b; i++)
    
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
    
const int INF = 0x3f3f3f3f, NINF = 0xf7f7f7f7;
const ll LINF = 0x3f3f3f3f3f3f3f3f, LNINF = 0xf7f7f7f7f7f7f7f7;
const ll MOD1 = 1e9+7, MOD2 = 1e9+9;
    
int t;
    
ll n, fat, v[100100], resp = 0, inv[100100];
    
ll binpow(ll x, ll y, ll mod){
    ll answ = 1;
    for(;y;y/=2){
            if(y&1)
                answ  = ((answ)*x)%MOD1;
            x = (x*x)%mod;
    }
    return answ;
}
    
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    for(int i=1;i<100100;i++)
        inv[i] = binpow(i, MOD1 - 2, MOD1);
    cin >> t;
    while(t--){
        cin >> n;
        fat = 1;
        for(ll i = 1; i <= n; ++i){
            cin >> v[i];
            fat = ((fat * v[i])%MOD1);
        }
        resp = 0;
        for(ll i = 1; i <= n; ++i){
            resp += ((((fat*inv[v[i]])%MOD1)*(v[i] - 1))%MOD1);
            resp %= MOD1;
        }
        cout << resp << '\n';
    }
}