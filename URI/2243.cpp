#include<bits/stdc++.h>
using namespace std;
#define N int(5e4)+3

int tentativa(int arr[N], int i, int n){
	int l = i-1, r = i+1, lim = arr[i]-1, ht = 1;
	while(l>=0 && r<=n-1 && lim>0){
		lim = min(lim,min(arr[l--],arr[r++]))-1;
		ht++;
	}
	return ht;
}

int main(){
	int arr[N], n;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	int answ = 0;
	for(int i=0;i<n;i++){
		answ = max(answ, tentativa(arr,i,n));
	}
	cout << answ << '\n';
	return 0;
}
