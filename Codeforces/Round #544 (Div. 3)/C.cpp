#include <bits/stdc++.h>
#define ll long long int
#define N 200010
using namespace std;

int main(){
	ll n;
	ll num[N];
	ll size=0;
	ll i, j;
	cin >> n;

	for(ll i=0;i<n;i++){
		cin >> num[i];
	}

	sort(num,num+n);
	for(i=0, j=0;i<n;i++){
		while(j<n && (num[j]-num[i]<=5)){j++;}
		size = max(size,j-i);
	}

	cout << size << '\n';

	return 0;
}
