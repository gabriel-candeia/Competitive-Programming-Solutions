#include<iostream>
#define N 100100
using namespace std;

int main(){
	int t[N];
	int n, tuna, eel, answ=0, i=0;

	cin >> n;

	for(int i=0;i<n;i++){
		cin >> t[i];
	}
	tuna = 0;
	eel = 0;
	while(i<n){
		if(t[i]==1){
			tuna = 0;			
			while(t[i]==1&&i<n){
				tuna++;
				i++;
			}
		}
		else if(t[i]==2){
			eel = 0;
			while(t[i]==2&&i<n){
				eel++;
				i++;
			}
		}
		answ = max(answ,2*min(eel,tuna));
	}

	cout << answ << '\n';

	return 0;
}