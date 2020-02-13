#include <bits/stdc++.h>
using namespace std;
#define N int(1e5)+5
#define M 1000000007

int main(){
	int arr[N], n;
	arr[1]=1; arr[2]=2; arr[3]=4;

	cin >> n;
	for(int i=4;i<=n;i++){
		arr[i] = ((arr[i-1] + arr[i-2])%M + arr[i-3])%M;
	}
	cout << arr[n] << '\n'; 
	return 0;
}
