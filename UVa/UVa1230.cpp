#include<iostream>
using namespace std;
#define ll long long int

ll binpow(ll x,ll k,ll n){
	if(k==0){
		return 1ll;
	}
	ll temp = binpow(x,k/2,n);
	if(k%2){
		return (temp*temp*x)%n;
	}
	else{
		return (temp*temp)%n;	
	}
}

int main(){
	int c;
	ll x, y, n;

	cin >> c;
	while(c--){
		cin >> x >> y >> n;
		cout << binpow(x,y,n) << '\n';
	}
	cin >> x;
	return 0;
}