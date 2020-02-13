#include<bits/stdc++.h>
#define N 300+5
using namespace std;

double prob[N][N];

double dragster(int **corridas, int n, int i, int winner){
	int w = corridas[i][winner], l = corridas[i][!winner];
	if(l==1){
		return 0;
	}
	else if(w<=n && l<=n){
		return prob[w][l];
	}
	else if(w<=n){
		return prob[w][l-n]
	}
	else{
		
	}
}

int main(){




	return 0
}