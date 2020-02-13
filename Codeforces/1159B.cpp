#include<bits/stdc++.h>
#define N int(3e5)+10
using namespace std;

int main(){
	int a[N], n;
	int answ=-1;

	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	answ = floor(min(a[n-1],a[0])/abs(n-1));
	for(int i=1;i<n-1;i++){
		answ = min(answ,(int) floor(min(a[i],a[0])/abs(i-0)));
		answ = min(answ,(int) floor(min(a[i],a[n-1])/abs(i-n+1)));
	}	

	cout << answ << '\n';

	return 0;
}