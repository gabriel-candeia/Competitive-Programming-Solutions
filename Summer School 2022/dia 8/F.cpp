#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll fib[100];
map<ll, vector<int>> mapa;

int main(){
	fib[0] = 0;
	fib[1] = 1;
	for(ll i = 2; i <= 23; i++)
		fib[i] = fib[i-1]+fib[i-2];
	ll n; cin >> n;
	for(ll i = 0, num; i < n; i++){
		cin >> num;
		mapa[num].emplace_back(i);
	}
	ll a = -1, b = -1;
	if(mapa.count(0) && mapa.count(1)){
		a = mapa[1][0];
		b = mapa[0][0];
	}else if(mapa[1].size() >= 2){
		a = mapa[1][0];
		b = mapa[1][1];
	}
	for(ll i = 3; i <= 23; i++){
		if(mapa.count(fib[i]) && mapa.count(fib[i-1])){
			a = mapa[fib[i]][0];
			b = mapa[fib[i-1]][0];
		}
	}
	if(a == -1){
		cout << "impossible\n";
	}else{
		cout << b+1 << " " << a+1 << "\n";
	}
	
	return 0;
}