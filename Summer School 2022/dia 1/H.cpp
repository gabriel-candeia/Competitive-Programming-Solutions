#include<bits/stdc++.h>
#define ll long long
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL);
#define maxn int(4e5+5)
using namespace std;

int n;
vector<int> arr;
array<int,100> st[maxn];
array<int,100> vazio;

array<int,100> combine(const array<int,100>& a, const array<int,100>& b){
    array<int,100> c;
    for(int i=0;i<100;i++)
        c[i] = a[i] + b[i];
    return c;
}

array<int,100> build(int p, int l, int r){
    if(l==r){
        for(int i=2;i<100;i++){
            while(arr[l]%i==0){
                st[p][i]++;
                arr[l]/=i;
            }
        }
        return st[p];
    }
    int med = l + (r-l)/2;
    return st[p] = combine(build(2*p,l,med),build(2*p+1,med+1,r));
}

array<int,100> get(int p, int l, int r, int i, int j){
    if(r<i || j<l){
        return vazio;
    }
    if(i<=l && r<=j){
        return st[p];
    }
    int med = l + (r-l)/2;
    return combine(get(2*p,l,med,i,j),get(2*p+1,med+1,r,i,j));
}

ll binpow(ll a, ll b, ll mod){
    ll answ = 1;
    for(;b;b/=2){
        if(b&1){
            answ = (answ*a)%mod;
        }
        a = (a*a)%mod;
    }
    return answ;
}

ll solve(int l, int r, ll mod){
    ll answ = 1;
    auto freq = get(1,0,n-1,l,r);

    for(int i=1;i<100;i++){
        if(freq[i]){
            answ = (answ*binpow(i,freq[i],mod))%mod;
        }
    };
    return (answ%mod);
}

int main(){
    fastio();
    cin >> n;
    arr.assign(n,0);
    for(auto &x:arr)
        cin >> x;
    build(1,0,n-1);
    int m;
    cin >> m;
    while(m--){
        int a, b, mod;
        cin >> a >> b >> mod;
        cout << solve(a-1,b-1,mod) <<"\n";
    }

    return 0;
}