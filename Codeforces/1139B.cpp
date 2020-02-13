#include<iostream>
#define ll long long int
#define N 200100

using namespace std;
	
int main(){
	ll a[N];
	ll stack[N];
	ll top = 0;
	ll n;
	ll sum;

	cin >> n;

	for(ll i=0;i<n;i++){
		cin >> a[i];
	}

	stack[top++] = a[n-1];
	for(ll i=n-2;i>=0;i--){
		if(a[i]<stack[top-1]){
			stack[top++] = a[i];
		}
		else if(a[i]==stack[top-1]){
			stack[top++] = (a[i]-1)*(a[i]!=0);	
		}
		else{
			stack[top++] = (stack[top-1]-1)*(stack[top-1]!=0);		
		}
	}
	sum=0;
	for(ll i=0;i<n;i++){
		sum+=stack[i];
	}

	cout << sum << endl;

	return 0;
}