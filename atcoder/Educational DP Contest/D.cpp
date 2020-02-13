#include<bits/stdc++.h>
#define W_max int(1e5)+10
#define N_max 100+10
#define ll long long int
using namespace std;

ll max(ll a, ll b){
	return (a>b) ? a : b;
}	

int main(){
	ll N, W, w[N_max], v[N_max], knapsack[2][W_max];
	ll current, last;

	//input
	cin >> N >> W;
	for(int i=0;i<N;i++){
		cin >> w[i] >> v[i];
	}
	//alg
	for(int i=0;i<W;i++){ knapsack[0][i] = 0;}
	for(int i=0;i<2	;i++){ knapsack[i][0] = 0;}

	for(int i=1;i<N+1;i++){ 
		current = i%2;
		last = (i-1)%2;
		for(int j=1;j<W+1;j++){
			//put last element in the knapsack
			knapsack[current][j] = knapsack[last][j];
			if(j>=w[i-1]){
				knapsack[current][j] = max(knapsack[last][j],knapsack[last][j-w[i-1]]+v[i-1]);
			}
		}
	}

	cout << knapsack[N%2][W] << '\n';

	return 0;
}