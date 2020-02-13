#include<iostream>
#include<cmath>
#define ll long long int
#define N 1000100

using namespace std;

int main(){
	ll n;
	ll x[N];
	ll sum;
	ll gugu;
	ll curr, min;

	while(scanf("%lld",&n)!=EOF){
		sum=0;
		for(ll i=0;i<n;i++){
			cin >> x[i];
			sum+=x[i];
		}
		curr =0;
		min = sum;
		gugu = sum;
		for(ll i=0;i<n;i++){
			curr+=x[i];
			gugu -= x[i];
			if(min>abs(gugu-curr)){
				min = abs(gugu-curr);
			}
		}

		cout << min << endl;
	}

	return 0;
}
