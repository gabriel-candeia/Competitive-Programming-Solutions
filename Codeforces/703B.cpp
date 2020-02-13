#include<bits/stdc++.h>
#define ll long long int
#define N int(1e5)+10
using namespace std;

int main(){
	ll n, k, c[N], id;
	ll aux=0, sum=0;

	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> c[i];
		aux+=c[i];
	}
	for(int i=0;i<k;i++){
		cin >> id;
		id--;
		aux-=c[id];
		sum += c[id]*(aux);	
		c[id] = 0;
	}
	for(int i=0;i<n;i++){
		sum += c[i]*c[(i+1)%n];
	}

	cout << sum << '\n';

	return 0;
}