#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	int a[1000];
	int pontos=0;

	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	for(int i=0;i<n-1;i++){
		if(a[i]*a[i+1]==6){
			pontos = -1;
			break;
		}
		else{
			pontos += max(a[i+1],a[i])+1;
		}
	}

	if(pontos==-1){
		cout << "Infinite\n";
	}
	else{
		for(int i=0;i<n-2;i++){
			if(a[i]==3&&a[i+1]==1&&a[i+2]==2){
				pontos--;
			}
		}
		cout << "Finite\n";
		cout << pontos << '\n';
	}

	return 0;
}

