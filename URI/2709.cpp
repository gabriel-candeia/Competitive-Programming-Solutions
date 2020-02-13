#include<bits/stdc++.h>
#define N 100
using namespace std;

bool ehprimo(int x){
	if(x<=1){
		return false;
	}
	int r = sqrt(x);
	for(int i=2;i<=r;i++){
		if(x%i==0){
			return false;
		}
	}
	return true;
}

int main(){
	int m, v[N], n,acm;

	while(cin >> m){
		for(int i=0;i<m;i++){
			cin >> v[i];
		}
		cin >> n;
		acm = 0;
		for(int i=m-1;i>=0;i-=n){
			acm+=v[i];
		}
		cout << ((ehprimo(acm) ? "You’re a coastal aircraft, Robbie, a large silver aircraft." : "Bad boy! I’ll hit you." )) << '\n';
	}

	return 0;
}

