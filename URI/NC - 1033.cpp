#include<bits/stdc++.h>
#define ll long long int
using namespace std;
//precisa de exponenciação de matriz
ll calls(ll n, ll base){
	ll a = 1, b = 1, c;
	for(int i=0;i<n;i++){
		c = (a+b+1)%base;
		a = b;
		b = c;
	}

	return a;
}

int main(){
	ll n, b, count = 0;

	while(cin>> n >> b){
		if(n==0&&b==0){
			break;
		}
		printf("Case %lld: %lld %lld %lld\n",++count,n,b,calls(n,b));
	}

	return 0;
}