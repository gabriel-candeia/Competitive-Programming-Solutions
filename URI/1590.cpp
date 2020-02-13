#include<bits/stdc++.h>
#define N 50
using namespace std;

//solução dp
int maxand(int arr[N], int n, int k, int i,int acm){
	if(k==0){
		return acm;
	}
	else if(i==n){
		return 0;
	}
	return max(maxand(arr,n,k-1,i+1,acm&arr[i]),maxand(arr,n,k,i+1,acm));
}

//soluçao gulosa
int split(int arr[N],int n, int k){
	int topo = 0, temp;
	for(int i=0;i<n;i++){
		if((arr[i]>>(31-k))%2==1){
			temp = arr[topo];
			arr[topo] = arr[i];
			arr[i] = temp;
			topo++;
		}
	}
	return topo;
}

int greedy_and(int arr[N], int n, int k){
	int answ[N], cont = 0, last = 0, tam =n;
	for(int i=0;i<=31;i++){
		last = split(arr,n,i); 
		if(last>=k){
			n = last;
		}
		answ[i] = (last>=k);
	}
	for(int i=0;i<=31;i++){
		cont = (cont<<1) + answ[i]; 
	}
	return cont;
}

int main(){
	int t, n, k, arr[N];
	int acm = INT_MAX;

	cin >> t;
	while(t--){

		cin >> n;
		cin >> k;
		for(int i=0;i<n;i++){
			cin >> arr[i];
		}
		//cout << maxand(arr,n,k,0,acm) << '\n';
		cout << greedy_and(arr,n,k) << '\n';
	}
	return 0;
}

/*
	greedyand
		começamos pelo bit mais significativo,
		só é possivel que aquele bit esteja na resposta se existirem 
		pelo menos k valores em arr onde aquele bit é 1,
		para cada iteração vamos percorrer arr i e manter no começo
		de arr i os valores onde o i-ésimo bit é 1, caso a quantidade 
		desses valores ultrapassem k tornamos answ[i] = 1, caso contrário
		paramos
	*/
