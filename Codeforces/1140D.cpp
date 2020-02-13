#include<iostream>
#define ll long long int
using namespace std;

int main(){
	ll n;
	ll sum;

	cin >> n;
	sum=0;
	for(ll i=2;i<n;i++){
		sum+=i*(i+1);
	}
	cout << sum << endl;
	return 0;
}