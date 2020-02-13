#include<bits/stdc++.h>
#define ll long long int
#define pow2(i) i*i
using namespace std;

int main(){
	ll c, sum, n, acm;

	cin >> n;
	while(n--){
		cin >> c >> sum;
		acm = pow2((sum/c))*(c-sum%c) + pow2((sum/c+1))*(sum%c);
		cout << acm << '\n';
	}

	return 0;
}
