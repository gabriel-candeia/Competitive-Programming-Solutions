#include<bits/stdc++.h>
#define N int(3e3)+10
using namespace std;

double coins(double p[N],int n,int i,int heads){
	if(i==n){
		if(heads>n-heads){
			return 1;
		}
		return 0;
	}
	return p[i]*coins(p,n,i+1,heads+1) + (1-p[i])*coins(p,n,i+1,heads);
}

double memo[N][N];
double coins_dp(double p[N],int n){
	for(int j=0;j<=n;j++){
		memo[n][j] = (j>n-j);
	}

	for(int i=n-1;i>=0;i--){
		for(int j=i;j>=0;j--){
			memo[i][j] = p[i]*memo[i+1][j+1] + (1-p[i])*memo[i+1][j];
		}
	}

	return memo[0][0];
}

int main(){
	int n;
	double p[N];

	cin >> n;
	for(int i=0;i<n;i++){
		cin >> p[i];
	}
	printf("%.15lf\n",coins_dp(p,n));
	return 0;
}