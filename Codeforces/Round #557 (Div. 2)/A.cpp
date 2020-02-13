#include<bits/stdc++.h>
#define N 100
using namespace std;

int main(){
	int houses[N];
	int n, m, h;
	int l, r, x;
	int acm;

	cin >> n >> h >> m;
	for(int i=1;i<=n;i++){
		houses[i] = h;
	}

	while(m--){
		cin >> l >> r >> x;
		for(int i=l;i<=r;i++){
			houses[i] = min(houses[i],x);
		}
	}

	acm = 0;
	for(int i=1;i<=n;i++){
		acm+= houses[i]*houses[i];
	}

	cout << acm << '\n';

	return 0;
}