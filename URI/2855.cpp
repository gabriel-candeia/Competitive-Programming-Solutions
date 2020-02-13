#include<bits/stdc++.h>
#define N 305000+3
using namespace std;

bool func(int n,int k){
	if(n%k==0){
		return false;
	}
	else if(n<k){
		return true;
	}
	return func((k-1)*(n/k)+n%k,k+1);
}

int bs(int vet[N], int l, int r, int k){
	int med= l + (r-l)/2;
	while(l<=r && vet[med]!=k){
		med = l + (r-l)/2;
		if(vet[med]>k){
			r = med-1;
		}
		else{
			l = med+1;
		}
	}
	return med;
}

int main(){
	int n, m, vet[N];

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while(cin >> n){
		for(int i=0;i<n;i++){
			cin >> vet[i];
		}
		cin >> m;
		m = bs(vet,0,n-1,m)+1;
		cout << (func(m,2) ? "Y" : "N") << '\n';
	}

	return 0;
}
