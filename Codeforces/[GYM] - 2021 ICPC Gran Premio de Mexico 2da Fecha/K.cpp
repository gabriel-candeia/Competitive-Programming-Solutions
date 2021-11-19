#include<bits/stdc++.h>
#define maxn int(1e6+5)
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL);
#define ll long long
using namespace std;

//valor[k] = numero de strings binarias de tamanho k que podem ser formadas concatenando
//para um k qualquer o numero de strings binárias que da pra formar contatenando é 
//para cada divisor xi de k valor[x1]+valor[x2]+valor[x3]+...
//valor[k] = 2**k - valor[x1]*valor[x2]*valor[x3]*... considerando que valor[x1], valor[x2], valor[x3] não foi calculado
//os casos bases são os k primos onde valor[k] == 2**k

// x1 z zzzz

// -
// 11, 00
// 000, 111
// 0000, 1111, 0101, 1010
// 00000, 11111

// 6
// 00 00 00
// 01 01 01
// 10 10 10
// 11 11 11
// 000 000
// 001 001
// 010 010
// 011 011
// 100 100
// 101 101
// 110 110
// 111 111

// 000000
// 111111
// 101010
// 010101
// 001001
// 010010
// 100100
// 101

//0, 1
//10, 01
//001, 010, 100, 101, 110, 011
// 0001, 0010, 0011, 0100, 0110, 0111, 1000, 1001, 1011, 1100, 1101, 1110

//001001001


// uma string binaria z que não possa ser formada a partir da concatenação de algo menor
// mas que zz possa ser formada pela concatenação de algo menor que z, zz seja yyy 
// z = y+algo1, z = algo2+y, y = algo1+algo2
// 111 111 111 

const ll mod = 1e9+7;
ll k; 
vector<ll> answ(1e6+5,0);  

ll binpow(ll b, ll e){
    ll ans = 1;
    while(e){
        if(e&1)
            ans = ((ans%mod)*(b%mod))%mod;
        b = (b*b)%mod; 
        e >>= 1;
    }
    return ans; 
}


void precomp(){
    answ[1] = 0;
    for(int i=1;i<maxn;i++){
        answ[i] = ((binpow(2,i) -answ[i])%mod+mod)%mod;
        for(int j=2*i;j<maxn;j+=i){
            answ[j] = (answ[j]+answ[i])%mod;
        }
    }
}

int main(){
    fastio();
    int t;

    cin >> t;
    precomp();
    while(t--){
        ll n;
        cin >> n;
        cout << ((binpow(2,n)-answ[n])%mod+mod)%mod << "\n";
    }
    
    return 0;
}