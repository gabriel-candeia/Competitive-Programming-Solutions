#include<bits/stdc++.h>
#define N 2000
using namespace std;

int main(){
	int n, k;
	int time, maxFuel, currentFuel;
	int d[N], s[N];
	int wt;

	cin >> n >> k;
	

	for(int i=0;i<n;i++){
		cin >> d[i];
	}
	for(int i=0;i<n;i++){
		cin >> s[i];
	}

	time = 0;
	maxFuel = 0;
	currentFuel = 0;
	for(int i=0;i<n;i++){
		currentFuel+=s[i];
		if(maxFuel<s[i]){
			maxFuel = s[i];
		}

		if(currentFuel>d[i]){
			time+=d[i];
			currentFuel-=d[i];
		}
		else{
			wt = ceil((d[i]-currentFuel)*1.0/maxFuel);
			time+=k*wt+d[i];
			currentFuel+=maxFuel*wt-d[i];
		}
	}
	cout << time << "\n";

	return 0;
}