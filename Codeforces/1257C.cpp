#include<bits/stdc++.h>
#define N int(2e5)+3
using namespace std;


int main(){
	int occ[N], answ;
	int t, n, a;

	cin >> t;
	while(t--){
		cin >> n;
		answ = n+1;
		for(int i=0;i<=n;i++){
			occ[i] = -1;
		}
		for(int i=0;i<n;i++){
			cin >> a;
			if(occ[a]!=-1){
				answ = min(answ,i-occ[a]+1);
			}
			occ[a] = i;
		}
		if(answ==n+1){ answ = -1;}
		cout << answ << '\n';
	}



	return 0;
}