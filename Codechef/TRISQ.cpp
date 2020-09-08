#include<bits/stdc++.h>
#define N 10010
using namespace std;

int quadrados(int x){
	if(x<4) return 0;
	if(x==4) return 1;

	return quadrados(x-2) + (x-4)/2 + 1;
}

int memo[N];
int quadrados_it(int x){
	for(int i=0;i<4;i++){
		memo[i] = 0;
	}
	memo[4] = 1;

	for(int i=5;i<=x;i++){
		memo[i] = memo[i-2]+((i-4)/2)+1;
	}

	return memo[x];
}

int main(){
	int t, n;

	cin >> t;
	while(t--){
		cin >> n;
		cout << quadrados_it(n) <<'\n';
	}
	return 0;
}
