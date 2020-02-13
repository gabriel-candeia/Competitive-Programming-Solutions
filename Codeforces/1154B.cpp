#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, temp;
	int diferentes=1;
	int a[110];

	cin >> n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	sort(a,a+n);

	for(int i=1;i<n;i++){
		diferentes+=(a[i]!=a[i-1]);
	}

	if(diferentes==1){
		cout << "0\n";
	}
	else if(diferentes>=4){
		cout << "-1\n";
	}
	else if(diferentes==2){
		if((a[0]+a[n-1])%2){
			cout << (a[n-1]-a[0])<<'\n';
		}
		else{
			cout << ((a[n-1]+a[0])/2-a[0])<<'\n';		
		}
	}
	else if(diferentes==3){
		int med;
		for(int i=0;i<n;i++){
			if(a[i]!=a[0]&&a[i]!=a[n-1]){
				med=a[i];
				break;
			}
		}
		if(med-a[0]==a[n-1]-med){
			cout << med-a[0] << '\n';
		}
		else{
			cout << "-1\n";			
		}
	}

	return 0;
}