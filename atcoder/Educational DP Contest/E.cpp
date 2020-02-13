#include<bits/stdc++.h>
#define N int(1e5)+10
#define ll long long int
using namespace std;

int main(){
	ll n, w, current, last, t=0;
	ll knapsack[2][N];
	ll weights[100], values[100];

	cin >> n >> w;
	for(int i=0;i<n;i++){
		cin >> weights[i] >> values[i];
		t+=values[i];
	}

	for(int i=0;i<N;i++){
		knapsack[0][i] = 0;
		knapsack[1][i] = 0;
	}

	for(int i=1;i<=n;i++){
		current = i%2;
		last = (i+1)%2;
		for(int j=0;j<=t;j++){
			//add (i-1)th element if its value doesn't exceed j
			if(values[i-1]<=j&&(knapsack[last][j-values[i-1]]!=0)){
				if(knapsack[last][j]==0){
					knapsack[current][j] = knapsack[last][j-values[i-1]]+weights[i-1];	
				}
				else{
					knapsack[current][j] = min(knapsack[last][j],knapsack[last][j-values[i-1]]+weights[i-1]);
				}
			}
			//can't add (i-1)th element
			else{
				knapsack[current][j] = knapsack[last][j];
			}
		}
		if(knapsack[current][values[i-1]]!=0){
			knapsack[current][values[i-1]] = min(knapsack[current][values[i-1]],weights[i-1]);
		}
		else{
			knapsack[current][values[i-1]] = weights[i-1];			
		} 
	}
	
	for(int j=t;j>=1;j--){
		if(knapsack[current][j]<=w && knapsack[current][j]!=0){
			cout << j << '\n';
			break;
		}
	}

	return 0;
}