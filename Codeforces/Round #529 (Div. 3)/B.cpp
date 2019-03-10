#include<iostream>
#include<algorithm>
#define ll long long int
using namespace std;

int main(){
	ll input[100100];
	ll n, removeMin, removeMax;

	cin >> n;

	for(int i=0;i<n;i++){
		cin >> input[i];
	}

	sort(input,input+n);

	removeMin = (n==1) ? 0 : (input[n-1] - input[1]);
	removeMax = (n==1) ? 0 : (input[n-2] - input[0]);
	
	cout << min(removeMin,removeMax) <<'\n';
	return 0;
}
