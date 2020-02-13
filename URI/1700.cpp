#include<bits/stdc++.h>
#define N 1003
using namespace std;

int memo[N][][]

int mss(int arr[N], int n, int i, int s1, int s2){
	if(i==n){
		return (s1==s2) ? s1 : 0;
	}
	return max(mss(arr,n,i+1,s1,s2),max(mss(arr,n,i+1,s1+arr[i],s2),mss(arr,n,i+1,s1,s2+arr[i])));
}


int main(){
	int n, arr[N];

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while(true){
		cin >> n;
		if(n==0){
			break;
		}
		for(int i=0;i<n;i++){
			cin >> arr[i];
		}
		cout << mss(arr,n,0,0,0) << '\n';
	}
	return 0;
}
