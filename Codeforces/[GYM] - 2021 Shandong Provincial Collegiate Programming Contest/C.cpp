#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll mul(ll a, ll b, ll m) {
	ll ret = a*b - (ll)((long double)1/m*a*b+0.5)*m;
	return ret < 0 ? ret+m : ret;
}

ll gcd(ll a, ll b){
	return (b) ? gcd(b,a%b) : a;
}

ll binpow(ll a, ll b, ll m){
    ll c=1;
    for(; b; b=b>>1,a = mul(a,a,m))
        if(b&1)
            c = mul(c,a,m);
    return c;
}

bool miller_rabin(ll n) {
    if(n<=1) return false;
    ll r = __builtin_ctzll(n-1), d = (n-1)>>r;

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
        if (n == a) return true;
        ll x = binpow(a,d,n);
        bool is_prime = (x==1 || x==n-1);
        for(int i=0; i<r && !is_prime; i++, x=mul(x,x,n))
            is_prime |= (x==n-1);
        if(!is_prime) return false;
    }
    return true;
}

ll rho(ll n) {
	if (n == 1 or miller_rabin(n)) return n;
	auto f = [n](ll x) {return mul(x, x, n) + 1;};

	ll x = 0, y = 0, t = 30, prd = 2, x0 = 1, q;
	while (t % 40 != 0 or gcd(prd, n) == 1) {
		if (x==y) x = ++x0, y = f(x);
		q = mul(prd, abs(x-y), n);
		if (q != 0) prd = q;
		x = f(x), y = f(f(y)), t++;
	}
	return gcd(prd, n);
}

vector<ll> fact(ll n) {
	if (n == 1) return {};
	if (miller_rabin(n)) return {n};
	ll d = rho(n);
	vector<ll> l = fact(d), r = fact(n / d);
	l.insert(l.end(), r.begin(), r.end());
	return l;
}

int vid = 1;
vector<pair<int,int>> edges;

void solve(ll k, int id){
    if(k==2) return;
    auto arr = fact(k-1);
    if(arr.size()==0){
        edges.push_back({id,++vid});
        solve(k-1,vid);
    }
    else{
        for(auto x:arr){
            edges.push_back({id,++vid});
            solve(x,vid);
        }
    }
}

int main(){
    ll k;

    cin >> k;
    solve(k,vid);
    cout << edges.size()+1 << "\n";
    for(auto p:edges){
        cout << p.first << " " << p.second <<"\n";
    }

    return 0;
}