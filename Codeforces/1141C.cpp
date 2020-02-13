#include<iostream>
#define N 200010
using namespace std;

int main(){
	int q[N];
	int p[N];
	int somas[N];
	int n;
	int menor;
	int menorI;
	int existe[N] = {false};
	cin >> n;
	for(int i=0;i<n-1;i++){
		cin >> q[i];
	}
	somas[0] = 0;
	for(int i=1;i<n;i++){
		somas[i]=somas[i-1]+q[i-1];
	}

	menor = somas[0];
	menorI = 0;
	for(int i=0;i<n;i++){
		if(somas[i]<menor){
			menor = somas[i];
			menorI = i;
		}
	}

	p[menorI] = 1;
	for(int i=menorI-1;i>=0;i--){
		p[i] = p[i+1]-q[i];
	}
	for(int i=menorI;i<n-1;i++){
		p[i+1] = p[i]+q[i];
	}
	for(int i=0;i<n;i++){
		if(p[i]>=0 && p[i]<=n){
			if(existe[p[i]]==true){
				cout << "-1" << '\n';
				return 0;
			}
		}
		if(p[i]>=0 && p[i]<=n){
			existe[p[i]]=true;
		}
	}
	for(int i=1;i<=n;i++){
		if(existe[i]==false){
			cout << "-1" << '\n';
			return 0;
		}
	}
	for(int i=0;i<n-1;i++){
		cout << p[i] <<' ';
	}

	cout << p[n-1] << "\n";
	return 0;
}








