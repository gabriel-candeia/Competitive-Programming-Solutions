#include<bits/stdc++.h>
#define W int(1e6)+10
#define N 25

using namespace std;

int knapsack[W], val[N], wt[N], n, w, t;
int main(){
	//input
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&w);
		for(int i=0;i<n;i++){
			cin >> wt[i];
			val[i] = 1;
		}
	
		for(int i=0;i<=w;i++){
			knapsack[i]=int(1e9);
		}
		for(int i=0;i<n;i++){
			knapsack[wt[i]] = 1;	
		}
	
		//alg
		for(int i=1;i<=w;i++){
			for(int j=0;j<n;j++){
				if(wt[j]<=i){
					knapsack[i]=min(knapsack[i],knapsack[i-wt[j]]+val[j]);
				}	
			}
		}	
	
		printf("%d\n",knapsack[w]);
	}
	return 0;
}
