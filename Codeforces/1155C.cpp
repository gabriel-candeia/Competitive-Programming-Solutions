#include<iostream>
#define N 300100
#define ll long long int
using namespace std;

ll gcd(ll a, ll b){
	if(b){
		return gcd(b,a%b);
	}
	return a;
}

int main(){
	ll n, m;
	ll x[N], p[N];
	ll aux;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for(ll i=0;i<n;i++){
		cin >> x[i];
	}

	for(ll i=0;i<m;i++){
		cin >> p[i];
	}

	aux = x[1]-x[0];
	for(ll i=1;i<n;i++){
		aux = gcd(aux,x[i]-x[i-1]);
	}
	for(ll i=0;i<m;i++){
		if(aux%p[i]==0){
			cout << "YES\n";
			cout << x[0] << ' ' << i+1<<'\n';
			return 0;
		}
	}

	cout << "NO\n";
	return 0;
}