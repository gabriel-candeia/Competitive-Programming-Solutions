#include<bits/stdc++.h>
using namespace std;
#define N 100+3

int knapsack(int c, int n, int v[N], int w[N]){
	int memo[N][1003];

	for(int i=0;i<=n;i++){ memo[i][0] = 0;}
	for(int i=0;i<=c;i++){ memo[0][i] = 0;}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=c;j++){
			memo[i][j] = memo[i-1][j];
			if(w[i]<=j){
				memo[i][j] = max(memo[i][j],memo[i-1][j-w[i]]+v[i]);
			}
		}
	}

	return memo[n][c];
}

int main(){
	int g, p, W, v[N], w[N], cont=0;;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> g;
	while(g--){
		cont++;
		cin >> p >> W;
		for(int i=1;i<=p;i++){
			cin >> v[i] >> w[i];
		}
		printf("Galho %d:\n",cont);
		printf("Numero total de enfeites: %d\n\n",knapsack(W,p,v,w));
	}

	return 0;
}
