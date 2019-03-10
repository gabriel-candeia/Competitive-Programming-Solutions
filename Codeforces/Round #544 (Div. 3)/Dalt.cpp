#include <bits/stdc++.h>
#define ll long long int
#define N 200010
using namespace std;

int compare(pair<ll,ll> a, pair<ll,ll> b){
	return -a.first*b.second < -b.first*a.second;
}

int main(){
	ll a[N], b[N];
	ll tempGcd;
	ll counter, counterMax;
	ll n;
	ll qtdPairs;
	ll anyD = 0;
	pair<ll,ll> pares[N];

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

	/*for(ll i=0;i<qtdPairs;i++){
		cout << "(" << pares[i].first << ',' << pares[i].second << ") ";
	}

	cout << "\nOrdenado:";*/

	sort(pares,pares+n,compare);

	for(ll i=0;i<qtdPairs;i++){
		cout << "(" << pares[i].first << ',' << pares[i].second << ") ";
	}

	cout << endl;

	counter = 0;
	counterMax = 0;
	for(ll i=0;i<qtdPairs-1;i++){
		if((pares[i].first==pares[i+1].first)&&(pares[i].second==pares[i+1].second)){
			counter++;
		}
		else{
			counterMax = max(++counter,counterMax);
			counter = 0;
		}
	}

	counterMax = (qtdPairs) ? max(++counter,counterMax) : 0;

	cout << counterMax+anyD << '\n';

	return 0;
}
