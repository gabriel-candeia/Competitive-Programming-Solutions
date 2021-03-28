#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll maxrope(ll n){
	return (n+3LL)*n/2LL;
}

ll minrope(ll l, ll r){
	if(r-l<=1){
		return 0;
	}
	ll med = (l+r)/2;
	return (r-l) + minrope(l, med) + minrope(med, r);
}

int main(){
	int t, n, m;
	int lb, ub;
	cin >> t;
	while(t--){
		cin >> n >> m;

		lb = minrope(0,n+1);
		ub = maxrope(n);

		if(lb<=m && m<=ub){
			cout << 0 << '\n';
		}
		else if(m<lb){
			cout << -1 << '\n';
		}
		else{
			cout << m-ub << '\n';
		}
	}

	return 0;
}