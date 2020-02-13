#include<bits/stdc++.h>
using namespace std;
#define N int(1e5)+3
#define ll long long int

ll energia(int arr[N],int n,int c,int m){
	int left = m, top = 0;
	ll acm = 0;
	while(left>0){
		acm += -2*arr[top];
		top += c;
		left-= c;
	}
	return acm;
}

int main(){
	int n, c, m, arr[N], t;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while(t--){
		cin >> n >> c >> m;
		for(int i=0;i<m;i++){
			cin >> arr[i];
			arr[i] *=-1;
		}
		sort(arr,arr+m);
		cout << energia(arr,n,c,m) << '\n';
	}
	return 0;
}
