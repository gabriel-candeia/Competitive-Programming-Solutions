#include<bits/stdc++.h>
#define ll long long int
#define N 100100

using namespace std;

int main(){
	ll n, k;
	ll num[N];
	ll soma;
	ll min;

	cin >> n >> k;
	for(ll i=0;i<n;i++){
		cin >> num[i];
	}	

	min = num[0];
	soma = 0;
	for(ll i=0;i<n;i++){
		if(num[i]<0&&k){
			num[i] = -num[i];
			k--; 
		}
		if(abs(num[i])<abs(min)){
			min = num[i];
		}
		soma+=num[i];
	}	

	if(k!=0&&k%2){
		soma -=2*abs(min);	
	}

	cout << soma << '\n';
	return 0;
}