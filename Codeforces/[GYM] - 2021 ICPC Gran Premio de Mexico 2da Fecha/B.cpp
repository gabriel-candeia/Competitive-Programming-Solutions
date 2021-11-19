#include <bits/stdc++.h>
using namespace std;
#define mod 998244353LL
#define maxn ll(1e5+10)

typedef long long int ll;

ll fat[maxn], inv[maxn], prefNum[maxn], prefDem[maxn];

ll binpow(ll b, ll e){
    if(e==0) return 1;
    ll ans = 1;
    while(e){
        if(e&1)
            ans = ((ans%mod)*(b%mod))%mod;
        b = (b*b)%mod; 
        e >>= 1;
    }
    return ans; 
}

ll invmod(ll num){
    return binpow(num, mod-2);
}

ll comb(ll n, ll k){
    return (((fat[n]*inv[k])%mod)*inv[n-k])%mod;
}

ll msb(ll num){
    ll ans = 0;
    while(num){
        ans = num%10;
        num /= 10;
    }
    return ans;
}

ll quanto(ll x){
    ll base = msb(x)+1;
    for(ll y = x;y;){
        y/=10;
        if(y)
            base*=10;
    }
    return base-x;
}

int main(){

    //Calculando Fatorial e Inverso Modular
    fat[0] = 1;
    inv[0] = 1;
    for(int i = 1; i < maxn; i++){
        fat[i] = (fat[i-1]*i)%mod;
        inv[i] = invmod(fat[i]);
    }

    ll n, m;
    cin >> n >> m;
    
    vector<ll> arr(n,0), dem(10,1), num(10,0);

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    for(int k=0;k<=m;k++){
        prefNum[k] = ((binpow(n-1,m-k)*comb(m,k))%mod);
        prefDem[k] =  binpow(n,m);
        if(k){
            prefNum[k] = ((prefDem[k]*prefNum[k-1])%mod + (prefDem[k-1]*prefNum[k])%mod)%mod;
            prefDem[k] = (prefDem[k]*prefDem[k-1])%mod;
        }
    }
    
    for(int i=0;i<n;i++){
        ll last = -1, k = m;
        while(k>=0){
            ll pos = msb(arr[i]), troca = min(quanto(arr[i]),k);
            if(troca==0)
                troca = 1;
            k-=troca;

            if(troca==0)
                break;

            ll incNum = prefNum[last+troca], incDem = prefDem[last+troca];
            if(last>=0){
                incNum = (((incNum*prefDem[last])%mod - (prefNum[last]*incDem)%mod)%mod+mod)%mod;
                incDem = (incDem*prefDem[last])%mod;
            }
            
            //incNum = ((binpow(n-1,m-k)*comb(m,k))%mod);
            //incDem = binpow(n,m);
            //cout << incNum << " " << incDem <<"\n";
        
            num[pos] = ((num[pos]*incDem)%mod + (incNum*dem[pos])%mod)%mod;
            dem[pos] = (dem[pos]*incDem)%mod;

            arr[i]+=troca;
            last +=troca;
        }
    }

    
    
    for(int i=1;i<10;i++)
        cout << (num[i]*invmod(dem[i]))%mod << "\n";

    return 0;
}