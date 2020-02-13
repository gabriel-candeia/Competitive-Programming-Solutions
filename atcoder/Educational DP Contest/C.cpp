#include<bits/stdc++.h>
#define N 100010

using namespace std;
int main(){
	int n, a[N],b[N],c[N], vacation[N][3];

	//input
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i] >> b[i] >> c[i];
	}

	//alg
	vacation[n+1][0] = 0;
	vacation[n+1][1] = 0;
	vacation[n+1][2] = 0;

	for(int i=n;i>=0;i--){
		vacation[i][0] = max(vacation[i+1][1],vacation[i+1][2]) + a[i];
		vacation[i][1] = max(vacation[i+1][0],vacation[i+1][2]) + b[i];
		vacation[i][2] = max(vacation[i+1][1],vacation[i+1][0]) + c[i];
	}

	cout << max(vacation[0][0],max(vacation[0][1],vacation[0][2])) << '\n';

	return 0;
}