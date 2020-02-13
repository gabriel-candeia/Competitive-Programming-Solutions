#include<bits/stdc++.h>
#define N 100010

using namespace std;

int main(){
	int n, k, h[N], cost[N];

	//input
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> h[i];
	}

	//alg
	cost[0]=0;
	for(int i=1;i<n;i++){
		cost[i] = int(1e9);
		for(int j=i-1;j>=max(0,i-k);j--){
			cost[i] = min(cost[i],cost[j]+abs(h[i]-h[j]));	
		}
	}

	cout << cost[n-1] << '\n';

	return 0;
}