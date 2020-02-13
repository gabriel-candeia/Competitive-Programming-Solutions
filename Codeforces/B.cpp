#include<bits/stdc++.h>

using namespace std;

long long int gcd(long long int a, long long int b){
	if(b==0){
		return a;
	}
	else{
		return gcd(b,a%b);
	}
}

int main(){
	long long int n,soma;
	bool poss;
	int cont =0;
	cin >> n;
	soma = n*(n+1)/2;
	poss = false;	
	for(int i=2;i<=n;i++){
		if(gcd(i,soma-i)!=1){
			poss = true;
			cout << "Yes\n";
			cout << 1 << ' '<< i << '\n';
			cout << n-1 << ' ';
			for(int j=1;j<=n;j++){
				if(j!=i){
					cout << j << ' ';
				}
			}
			cout << '\n';
			break;
		}
	}

	if(poss==false){
		cout << "No\n";
		cont++;
	}
	return 0;
}