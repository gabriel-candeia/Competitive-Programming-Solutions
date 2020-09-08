#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
	ll t;
	ll n, acm;

	cin >> t;
	while(t--){
		cin >> n;
		acm = (n*(n+1)/2) - 2*((pow(2,floor(log2(n))+1))-1);
		cout << acm << '\n';
	}


	return 0;
}