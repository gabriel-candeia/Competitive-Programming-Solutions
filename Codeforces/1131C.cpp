#include<iostream>
#include<algorithm>
#define ll long long int
using namespace std;



int main(){
	ll n;
	ll a[1000];
	ll b[1000];
	ll topb=0;
	cin >> n;

	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	sort(a,a+n);

	for(int i=0;i<n;i+=2){
		b[topb++]=a[i];
	}
	for(int i=n-1-1*(n%2);i>=0;i-=2){
		b[topb++]=a[i];	
	}

	for(int i=0;i<n;i++){
		cout << b[i] << ' ';
	}
	cout << "\n";
	return 0;
}