#include <bits/stdc++.h>
#define ll long long int
#define N 200010
using namespace std;

int main(){
	ll a[N], b[N];
	ll tempGcd;
	ll counter, counterMax;
	ll n;
	ll qtdPairs;
	ll anyD = 0;
	pair<ll,ll> pares[N];
	map<pair<ll,ll>,ll> mat;

	cin >> n;

	for(ll i=0;i<n;i++){
		cin >> a[i];
	}

	for(ll i=0;i<n;i++){
		cin >> b[i];
	}
	
	qtdPairs = 0;
	for(ll i=0;i<n;i++){
		if(a[i]!=0){
			tempGcd = __gcd(a[i],b[i]);
			pares[qtdPairs++] = pair<ll,ll>(b[i]/tempGcd,a[i]/tempGcd);
		}
		else if(b[i]==0){
			anyD++;
		}
	}	

	counter = 0;
	counterMax = 0;
	for(ll i=0;i<qtdPairs;i++){
		if(mat.count(pares[i])!=0){
			mat[pares[i]]++;
		}
		else{
			mat[pares[i]]=1;	
		}
		counterMax = max(mat[pares[i]],counterMax);
	}

	cout << counterMax+anyD << '\n';

	return 0;
}
