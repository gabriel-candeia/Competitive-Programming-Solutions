#include<bits/stdc++.h>
#define N 100100
#define ll long long int
using namespace std;

int main(){
	ll n, t;
	ll A[N];
	ll answ[N];

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while(t--){
		cin >> n;
		for(int i=0;i<n;i++){
			cin >> A[i];
		}

		answ[n-1] = 1;
		for(int i=n-2;i>=0;i--){
			if(A[i]*A[i+1]<0){
				answ[i] = 1+answ[i+1];
			}
			else{
				answ[i] = 1;	
			}
		}

		for(int i=0;i<n;i++){
			cout << answ[i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}