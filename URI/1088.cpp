#include<bits/stdc++.h>
#define N int(1e5)+3
#define ll long long int
using namespace std;
int L[N], n, p[N],answ;;

ll inv(int *p, int l, int med, int r){
	int n1 = med-l+1,i=0,j=med+1,k=l;
	ll cont;
	for(int i=0;i<n1;i++){
		L[i] = p[l+i];
	}
	while(i<n1 && j<=r){
		if(L[i]<=p[j]){
			p[k++] = L[i++];
		}
		else{
			p[k++] = p[j++];	
			cont += n1-i;
		}
	}
	while(i<n1){ p[k++] = L[i++];}
	return cont;
}

ll mergesort(int *p, int l, int r){
	if(l==r){ return 0;}
	int med = l + (r-l)/2;
	return mergesort(p,l,med)+mergesort(p,med+1,r)+inv(p,l,med,r);
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while(cin >> n){
		if(n==0){ break;}
		for(int i=0;i<n;i++){
			cin >> p[i];
		}
		answ = mergesort(p,0,n-1);
		if(answ%2){
			cout << "Marcelo\n";
		}
		else{
			cout << "Carlos\n";	
		}
	}
	return 0;
}
