#include<bits/stdc++.h>
#define T int(1e4)+10
using namespace std;

int main(){
	int n, t, six_flags[T], value[T], cost[T];
	int cont = 0;
	while(cin >> n >> t){
		//end
		if(n==0 && t==0){
			break;
		}
		//input
		for(int i=0;i<n;i++){
			cin >> cost[i] >> value[i];
		}
		//
		for(int i=0;i<=t;i++){
			six_flags[i] = 0;
			for(int j=0;j<=n;j++){
				if(cost[j]<=i){
					six_flags[i] = max(six_flags[i],six_flags[i-cost[j]]+value[j]);
				}
			}
		}
		cout << six_flags[t] << "\n";
	}

	return 0;
}
