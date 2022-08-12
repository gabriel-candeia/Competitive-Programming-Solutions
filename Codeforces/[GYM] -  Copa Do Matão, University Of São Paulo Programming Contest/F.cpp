#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll mul(ll a, ll b, ll m) {
	ll ret = a*b - ll((long double)1/m*a*b+0.5)*m;
	return ret < 0 ? ret+m : ret;
}

ll pow(ll x, ll y, ll m) {
	if (!y) return 1;
	ll ans = pow(mul(x, x, m), y/2, m);
	return y%2 ? mul(x, ans, m) : ans;
}

bool prime(ll n) {
	if (n < 2) return 0;
	if (n <= 3) return 1;
	if (n % 2 == 0) return 0;

	ll r = __builtin_ctzll(n - 1), d = n >> r;
	for (ll a : {2, 325, 9375, 28178, 450775, 9780504, 795265022}) {
		ll x = pow(a, d, n);
		if (x == 1 or x == n - 1 or a % n == 0) continue;
		
		for (ll j = 0; j < r - 1; j++) {
			x = mul(x, x, n);
			if (x == n - 1) break;
		}
		if (x != n - 1) return 0;
	}
	return 1;
}

ll rho(ll n) {
	if (n == 1 or prime(n)) return n;
	auto f = [n](ll x) {return mul(x, x, n) + 1;};

	ll x = 0, y = 0, t = 30, prd = 2, x0 = 1, q;
	while (t % 40 != 0 or __gcd(prd, n) == 1) {
		if (x==y) x = ++x0, y = f(x);
		q = mul(prd, abs(x-y), n);
		if (q != 0) prd = q;
		x = f(x), y = f(f(y)), t++;
	}
	return __gcd(prd, n);
}

vector<ll> fact(ll n) {
	if (n == 1) return {};
	if (prime(n)) return {n};
	ll d = rho(n);
	vector<ll> l = fact(d), r = fact(n / d);
	l.insert(l.end(), r.begin(), r.end());
	return l;
}

ll n, m;
vector<ll> base, basepow; 
set<ll> cj;
map<ll, ll> freq;

int main(){
    cin >> n >> m;
    for(ll i = 0, num; i < n; i++){
        cin >> num;
        cj.insert(num);
        freq[num]++;
    }
    map<ll, map<ll, ll>> mapa;
    for(ll num:cj){
        vector<ll> temp = fact(num);
        for(ll sla:temp)  ++mapa[num][sla];
    }

    vector<ll> ans;
    ans.emplace_back(n);
    ll one = freq[1LL];
    for(ll i = 2; i <= 64; i++){
        ll tot = 0; 
        for(auto mapa1:mapa){
            if(mapa1.first == 1LL) continue;
            bool ok = true;
            for(auto par:mapa1.second) 
                if(par.second%i != 0) 
                    ok = false;
            tot += freq[mapa1.first]*ok;
        }
        ans.emplace_back(tot+one);
    }
    ll pos;
    while(m--){
        cin >> pos;
        if(pos > 64) cout << one << "\n";
        else cout << ans[pos-1] << "\n";
    }

    return 0;
}
