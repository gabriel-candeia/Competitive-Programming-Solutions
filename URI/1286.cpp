#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, p, weight[40], value[40];
	int motoboy[40][40];

	while(true){
		cin >> n;
		if(n==0){
			break;
		}
		cin >> p;
		for(int i=0;i<n;i++){
			cin >> value[i] >> weight[i];
		}

		//basis cases
		for(int i=0;i<=p;i++){
			motoboy[0][i] = 0;
		}
		for(int i=0;i<=n;i++){
			motoboy[i][0] = 0;
		}

		//alg
		for(int i=1;i<=n;i++){
			for(int j=1;j<=p;j++){
				motoboy[i][j] = motoboy[i-1][j];
				if(weight[i-1]<=j){
					motoboy[i][j] = max(motoboy[i][j],motoboy[i-1][j-weight[i-1]]+value[i-1]);
				}
			}
		}

		cout << motoboy[n][p] << " min.\n";
	}

	return 0;
}
